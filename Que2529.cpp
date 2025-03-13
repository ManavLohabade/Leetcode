// Maximum Count of Posisitive Integer and Negative Integer 
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int n = nums.size();
            int l=0, r=n;
    
            int firstNonNeg = n;
    
            // first zero or positive number index 
            while(l<r) {
              int mid = l+(r-l)/2;
              if(nums[mid]>=0) {
                r = mid;
                firstNonNeg = mid;
                continue;
              } else {
                l = mid + 1;
              }
            }
    
            int firstPos = n;
    
            l = 0;
            r = n;
            // first positive number index 
            while(l<r) {
              int mid = l+(r-l)/2;
              if(nums[mid]>0) {
                r = mid;
                firstPos = mid;
                continue;
              } else {
                l = mid + 1;
              }
            }
    
            return max(n-firstPos, firstNonNeg);
            
        }
    };