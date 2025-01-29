// Remove Element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                ans.push_back(nums[i]);
            }
        }
        nums = ans;  
        return ans.size();
    }
};