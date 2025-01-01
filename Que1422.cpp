class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int one_count = 0;

        for (char c : s) {
            if (c == '1')
                one_count++;
        }

        int zero_count = 0;
        int max_score = 0;

        // Traverse the string and calculate score at each split point
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                zero_count++;
            } else {
                one_count--;
            }
            // Calculate the score for the current split point
            max_score = max(max_score, zero_count + one_count);
        }

        return max_score;
    }
};