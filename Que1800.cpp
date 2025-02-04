// Maximum Ascending Subarray Sum

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int maxi=nums[0],sum=nums[0];
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]>nums[i])
            {
                sum+=nums[i+1];
            }
            else
            {
                maxi=max(maxi,sum);
                sum=nums[i+1];
            } 
        }
         maxi=max(maxi,sum);
         return maxi;
    }
};