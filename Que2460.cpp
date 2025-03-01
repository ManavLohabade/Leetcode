// Apply Operations to an Array

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            for (int i = 0; i < n - 1; ++i) {
                if (nums[i] == nums[i + 1]) {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
            }
            stable_partition(begin(nums), end(nums), [] (int n) {
                return n != 0;
            });
            return nums;
        }
    };