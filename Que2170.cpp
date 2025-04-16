// Count Good Triplets in a array

class Solution {
    public:
        vector<int> bit;
        int n;
        int query(int i) {
            long long sum = 0;
            i++;
            while (i > 0) {
                sum += bit[i];
                i -= i & (-i);
            }
            return sum;
        }
        void update(int i, int x) {
            i++;
            while (i < n) {
                bit[i] += x;
                i += i & (-i);
            }
        }
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            n = nums1.size() + 1;
            bit.resize(n, 0);
            vector<int> mp(n - 1);
            for (int i = 0; i < n - 1; i++) {
                mp[nums2[i]] = i;
            }
            long long ans = 0;
            for (int i = 0; i < n - 1; i++) {
                int left_common = query(mp[nums1[i]]);
                int left_uncommon = i - left_common;
                int right_common = (n - mp[nums1[i]] - 2) - left_uncommon;
                ans += 1ll * left_common * right_common;
                update(mp[nums1[i]], 1);
            }
            return ans;
        }
    };