// Minimum length of string after operations

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int>mp;
        for(auto c : s){
            mp[c]++;
        }
        
        int ans = 0;
        for(auto p : mp){
            int count = p.second;
            while(count >= 3){
                count -= 2;
            }
            ans += count;
        }
        return ans;
    }
};