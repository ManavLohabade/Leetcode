// Sum of All Subset XOR Totals

class Solution {
    public:
        int helper(vector<int>& nums,int ind,int& ans,int xr){
            //base case
            if(ind<0) return ans+=xr;
    
            //pick
            helper(nums,ind-1,ans,xr^nums[ind]);
            //not pick
            helper(nums,ind-1,ans,xr);
            return ans;
        }
        int subsetXORSum(vector<int>& nums) {
            int n=nums.size();
            int ans=0;
            return helper(nums,n-1,ans,0);
            
        }
    };
    