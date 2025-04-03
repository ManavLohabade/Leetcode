// Solving Questions With Brainpower

class Solution {
    public:
        long long getAns(vector<vector<int>>& questions, int index) {
            if (index >= questions.size()) {
                return 0;
            }
            return max(getAns(questions, index + 1),
                       getAns(questions, index + questions[index][1] + 1) +
                           questions[index][0]);
        }
    
        long long getAnsBetter(vector<vector<int>>& questions, int index,
                               vector<long long>& dp) {
            if (index >= questions.size()) {
                return 0;
            }
            if (dp[index] != -1) {
                return dp[index];
            }
    
            long long ans =
                max(getAnsBetter(questions, index + 1, dp),
                    getAnsBetter(questions, index + questions[index][1] + 1, dp) +
                        questions[index][0]);
            dp[index] = ans;
            return ans;
        }
    
        long long mostPoints(vector<vector<int>>& questions) {
            vector<long long> dp(questions.size(), -1);
            return getAnsBetter(questions, 0, dp);
        }
    };