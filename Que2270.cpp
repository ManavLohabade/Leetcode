// Number of ways to split array

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        typedef long long ll;
        vector<ll> pre(n), suff(n);
       
        pre[0] = nums[0];
        suff[n - 1] = nums[n - 1];

        for (int i=1;i<n;i++) {
            pre[i] = pre[i-1] + nums[i];
        }
        for (int i = n-2;i>=0;i--) {
            suff[i] = suff[i+1] + nums[i];
        }
        int cnt = 0;
        for (int i=0;i<n-1;i++) {
            if (pre[i] >= suff[i+1]){
                cnt++;
                }
        }
        return cnt;
    }
    
};


