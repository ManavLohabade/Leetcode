// Apply Operations to maximize Score

vector<bool> v(100001);
int init = []() {
    int n = 100001;
    v[0] = 1, v[1] = 1;
    for (int i = 2; i * i < (n + 1); i++) {
        if (v[i] == 0)
            for (int j = i * i; j < (n + 1); j += i) {
                v[j] = 1;
            }
    }
    return 0;
}();
class Solution {
public:
    int md = 1000000007;
    int mp(long long n, long long x, int m) {
        if (x == 0)
            return 1;
        if (x % 2 == 0) {
            return mp((n * n) % m, x / 2, m);
        } else
            return (n * mp((n * n) % m, x / 2, m)) % m;
    }
    int maximumScore(vector<int>& nums, int k) {
        vector<int> m(nums.size());
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int c = 0;
            for (int k = 1; k <= sqrt(nums[i]); k++) {
                if (k == sqrt(nums[i])) {
                    if (nums[i] % k == 0 && v[k] == 0) {
                        c++;
                    }
                    continue;
                }
                if (nums[i] % k == 0) {
                    if (v[k] == 0)
                        c++;
                    if (v[nums[i] / k] == 0)
                        c++;
                }
            }
            m[i] = c;
        }
        vector<int> v, lb(n), rb(n);
        stack<int> st, s1;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && m[st.top()] < m[i]) {
                st.pop();
            }
            lb[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s1.empty() && m[s1.top()] <= m[i]) {
                s1.pop();
            }
            rb[i] = s1.empty() ? n : s1.top();
            s1.push(i);
        }
        vector<pair<int, int>> v1;
        for (int i = 0; i < n; i++) {
            v1.push_back({nums[i], i});
        }
        sort(v1.rbegin(), v1.rend());
        long long an = 1;
        for (int i = 0; i < v1.size(); i++) {
            int a = v1[i].first, b = v1[i].second;
            long long r = ((long long)(rb[b] - b) * (b - lb[b]));
            if (r < k) {
                k -= r;
                an = (mp(a, r, md) * an) % md;
            } else {
                an = (mp(a, k, md) * an) % md;
                break;
            }
        }
        return an;
    }
};