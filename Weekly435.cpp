// Q1.  Maximum difference between even and odd frequency I 

class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int maxOdd = INT_MIN, minEven = INT_MAX;
        for (int count : freq) {
            if (count > 0) {
                if (count % 2 == 0) {
                    minEven = min(minEven, count);
                } else {
                    maxOdd = max(maxOdd, count);
                }
            }
        }
        if (maxOdd == INT_MIN || minEven == INT_MAX)
            return 0;
        return maxOdd - minEven;
    }
    int main() {
        cout << maxDifference("aaaaabbc") << endl;
        cout << maxDifference("abcabcab") << endl;
        cout << maxDifference("aabbccdd") << endl;
        cout << maxDifference("aabbbc") << endl;
        return 0;
    }
};

// Q2.  Maximum Manhattan distance distance after K changes

class Solution {
public:
    int maxDistance(string s, int k) {
        int north = count(s.begin(), s.end(), 'N');
        int south = count(s.begin(), s.end(), 'S');
        int east = count(s.begin(), s.end(), 'E');
        int west = count(s.begin(), s.end(), 'W');

        int y = north - south;
        int x = east - west;
        int maxDist = abs(x) + abs(y);

        maxDist += min(k, (int)s.length());

        return maxDist;
    }

    int main() {

        cout << maxDistance
            ("NWSE", 1) << endl;
        cout << maxDistance
            ("NSWWEW", 3) << endl;
        cout << maxDistance
            ("NNNSSS", 10) << endl;
        cout << maxDistance
            ("EEEWWWNNSS", 5) << endl;
        cout << maxDistance
            ("NNNN", 2) << endl;
        cout << maxDistance
            ("EEEE", 0) << endl;
        return 0;
    }
};