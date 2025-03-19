// Longest Nice Subarray 

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int result = 1;
            int n = nums.size();
            int l = 0, r = 0; 
            int bitMask = 0;
            while(r < n) {
              while((bitMask & nums[r]) != 0) {
                bitMask ^= nums[l];
                l++;
              }
              bitMask |= nums[r];
              result = max(r-l+1, result);
              r++;
            }
            return result;
        }
    };