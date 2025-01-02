// Count vowel String in a Range

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {

        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        vector<int> v(words.size(), 0);

        for (int i = 0; i < words.size(); i++) {
            if (s.find(words[i][0]) != s.end() &&
                s.find(words[i][words[i].size() - 1]) != s.end()) {
                v[i] = 1;
            }
        }

        // Build prefix sum array
        for (int i = 1; i < v.size(); i++) {
            v[i] += v[i - 1];
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if (start > 0) {
                ans.push_back(v[end] - v[start - 1]);
            } else {
                ans.push_back(v[end]);
            }
        }

        return ans;
    }
};
