// Partition Array According to given Pivot

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> result(nums.size());
            int index = 0;
    
            for (int i=0;i<nums.size();i++) {
                if (nums[i] < pivot) {
                    result[index++] = nums[i];
                }
            }
    
            for (int i=0;i<nums.size();i++) {
                if (nums[i] == pivot) {
                    result[index++] = nums[i];
                }
            }
    
            for (int i=0;i<nums.size();i++) {
                if (nums[i] > pivot) {
                    result[index++] = nums[i];
                }
            }
    
            return result;
        }
    };