// Maximum Value of an ordered triplet II

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long ans = 0;
            int diff = nums[0] - nums[1];
            int mx = max(nums[0], nums[1]);
            for(int i = 2 ; i < n ; i++){
                if(diff > 0){
                    ans = max(ans, (long long)nums[i] * diff);
                }
                diff = max(diff, mx - nums[i]);
                mx = max(mx, nums[i]);
            }
            return ans;
        }
    };