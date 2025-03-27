// minimum Index of a valid split

class Solution {
    public:
        int findDominant(vector<int>& nums) {
            int candidate = nums[0], count = 1;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == candidate)
                    count++;
                else {
                    count--;
                    if (count == 0) {
                        candidate = nums[i];
                        count = 1;
                    }
                }
            }
            int freq = 0;
            for (int num : nums)
                if (num == candidate)
                    freq++;
            return (freq > nums.size() / 2) ? candidate : -1;
        }
    
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            int dom = findDominant(nums);
            if (dom == -1)
                return -1;
            vector<int> pre(n), suf(n);
            for (int i = 0; i < n; i++) {
                if (i == 0)
                    pre[i] = (nums[i] == dom);
                else
                    pre[i] = pre[i - 1] + (nums[i] == dom);
            }
            for (int i = n - 1; i >= 0; i--) {
                if (i == n - 1)
                    suf[i] = (nums[i] == dom);
                else
                    suf[i] = suf[i + 1] + (nums[i] == dom);
            }
            for (int i = 0; i < n - 1; i++) {
                int l = i + 1;
                int r = n - i - 1;
                if (pre[i] * 2 > l && suf[i + 1] * 2 > r)
                    return i;
            }
            return -1;
        }
    };