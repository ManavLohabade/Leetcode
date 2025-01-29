// Search Insert position 

class Solution {
public:
    int findindex(int target, int start, int end, vector<int>& nums){
        if (start > end)
            return start;
        int middle = (start + end) / 2;
        if (nums[middle] == target)
            return middle;
        else if (nums[middle] > target)
            return findindex(target, start, middle - 1, nums);
        else
            return findindex(target,middle + 1, end, nums);
            
        }
    int searchInsert(vector<int>& nums, int target) {
        return findindex(target, 0, nums.size() - 1, nums);
        
    }
};