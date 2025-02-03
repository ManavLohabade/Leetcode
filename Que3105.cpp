// Longest Strictly increasing or strictly decreasing subsequence

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        int c1 = 0;
        int c2 = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                c1++;
            } else {
                if ((c1+1) > ans) {
                    ans = c1 +1;
                }
                c1=0;
            }
            if (nums[i] < nums[i - 1]) {
                c2++;
            } else {
                if ((c2 +1) > ans) {
                    ans = c2 +1;
                }
                c2 =0;
            }
        }
        if ((c1 + 1) > ans) {
            ans = c1 +1;
        }
        if ((c2 + 1) > ans) {
            ans = c2 +1;
        }
        return ans ==0 ? 1 : ans ;
    }
};