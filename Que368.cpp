// Largest Divisible Subset 

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size(), maxInd = 0, maxLen = 0, maxCurr;
            vector<int> dp(n, 1), ans; 
            vector<int> PrevMaxLocation(n, -1); 
            sort(nums.begin(), nums.end());
    
            for (int i = 1; i < n; i++) {
                maxCurr = 0;
                for (int j = 0; j < i; j++) {
                    if (nums[i] % nums[j] == 0) {
                        if (maxCurr < dp[j]) {
                            maxCurr = dp[j];
                            PrevMaxLocation[i] = j;
                        }
                    }
                }
                dp[i] += maxCurr;
                if (maxLen < dp[i]) {
                    maxLen = dp[i];
                    maxInd = i;
                }
            }
    
            while (maxInd >= 0) {
                ans.push_back(nums[maxInd]);
                maxInd = PrevMaxLocation[maxInd];
            }
    
            return ans;
        }
    };