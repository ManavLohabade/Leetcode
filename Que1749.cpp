// Maximum absolute sum of any subarray

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
           int maxSum = 0,minSum = 0;
           int prefixSum = 0;
           for(int ele : nums){
            prefixSum +=ele;
            maxSum = max(maxSum , prefixSum);
            minSum = min(minSum, prefixSum);
           } 
           return maxSum - minSum;
        }
    };