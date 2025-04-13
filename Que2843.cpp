// Count symmetric Integers 

class Solution {
    public:
        long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                      string s) {
            string start_ = to_string(start), finish_ = to_string(finish);
            return countNumbers(finish_, s, limit) -
                   countNumbers(to_string(start - 1), s, limit);
        }
    
        long long countNumbers(string x, string s, int limit) {
            if (x.length() < s.length()) {
                return 0;
            }
            if (x.length() == s.length()) {
                return x >= s ? 1 : 0;
            }
            string suffix = x.substr(x.length() - s.length());
            long long count = 0;
            int prefixLength = x.length() - s.length();
            for (int i = 0; i < prefixLength; i++) {
                if (x[i] - '0' > limit) {
                    count += pow(limit + 1, prefixLength - i);
                    return count;
                }
                count += (x[i] - '0') * pow(limit + 1, prefixLength - 1 - i);
            }
            if (suffix >= s) {
                count++;
            }
    
            return count;
        }
    };