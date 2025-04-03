// Maximum value of an Ordered Triplet I

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long mx_ele=0, mx_diff=0, mx_trip=0;
            for(int i=0;i<n;++i){
                mx_trip = max(mx_trip, mx_diff*nums[i]);
                if(i<n-1){
                    mx_diff = max(mx_diff, mx_ele-nums[i]);
                    mx_ele = max(mx_ele, (long long)nums[i]);
                }
            }
            return mx_trip;
        }
    };