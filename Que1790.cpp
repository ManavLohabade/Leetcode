// Check if one String can make string equal 

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> unequalIndices;
        for (int i = 0; i < s1.size(); i++) {

            if (s1[i] != s2[i]) {
                unequalIndices.push_back(i);
                if (unequalIndices.size() > 2)
                    return false;
            }
        }

        int size = unequalIndices.size();
        if (size == 0)
            return true;
        else if (size == 1)
            return false;
        else if (size == 2) {
            std::swap(s1[unequalIndices[0]], s1[unequalIndices[1]]);
            return s1 == s2;
        }

        return false;
    }
};