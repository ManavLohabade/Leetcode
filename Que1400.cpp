// Construct k palindrome strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) {
            return false;
        }
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        int single = 0;
        for (auto val : mp) {
            single += (val.second % 2);
        }
        return single <= k ? true : false;
    }
};