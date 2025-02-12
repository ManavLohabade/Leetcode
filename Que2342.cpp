// Max suum of a pair with equal sum of digits 

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            //firstly check the sum of elemsts at indexes
            //find the maximum of the elemsts at that indexes
    //    int n = nums.size();
    //         int maxSum = -1;
            
    //         for (int i = 0; i < n; i++) {
    //             for (int j = i + 1; j < n; j++) {
    //                 int sum_i = 0, sum_j = 0, temp_i = nums[i], temp_j = nums[j];
                    
    //                 while (temp_i) {
    //                     sum_i += temp_i % 10;
    //                     temp_i /= 10;
    //                 }
                    
    //                 while (temp_j) {
    //                     sum_j += temp_j % 10;
    //                     temp_j /= 10;
    //                 }
                    
    //                 if (sum_i == sum_j) {
    //                     maxSum = max(maxSum, nums[i] + nums[j]);
    //                 }
    //             }
    //         }
            
    //         return maxSum;
    unordered_map<int, int> digitSumMap;
            int maxSum = -1;
            
            for (int num : nums) {
                int digitSum = 0, temp = num;
                while (temp) {
                    digitSum += temp % 10;
                    temp /= 10;
                }
                
                if (digitSumMap.count(digitSum)) {
                    maxSum = max(maxSum, digitSumMap[digitSum] + num);
                }
                
                digitSumMap[digitSum] = max(digitSumMap[digitSum], num);
            }
            
            return maxSum;
        }
    };