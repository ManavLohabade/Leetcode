// Count Prefix and Suffix Paris I

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            string s1 = words[i];
            int len1 = s1.length();

            for (int j = i + 1; j < n; j++) { 
                string s2 = words[j];
                int len2 = s2.length();

                if (len2 >= len1) {
                    string prefix = s2.substr(0, len1);            
                    string suffix = s2.substr(len2 - len1, len1);   

                    if (prefix == s1 && suffix == s1) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};