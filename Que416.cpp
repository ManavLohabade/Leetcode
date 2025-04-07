// Partition Equal Subset Sum 

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int n = nums.size() , sum = accumulate(nums.begin() , nums.end() , 0);
            if(sum & 1)return false;
            sum /= 2;
            vector<bool> dp(sum+1 , false);
            //base case
            dp[0] = true;
            //dp
            for(int i=0;i<n;i++){
                for(int j=sum;j>=nums[i];j--){
                    dp[j] = dp[j] | dp[j-nums[i]];
                }
            }
            return dp[sum];
        }
    };