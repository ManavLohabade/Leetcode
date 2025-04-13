// 3516 Find Closest Person 

class Solution {
    public:
        int findClosest(int x, int y, int z) {
            int a = abs(x - z);
            int b = abs(y - z);
            return a < b ? 1 : a > b ? 2 : 0;
        }
    };

// 3517 Smallest Palindromic Rearrangement I

class Solution {
    public:
        string smallestPalindrome(string s) {
            vector<int> c(26,0);
            for(char x: s) c[x-'a']++;
            string l;
            char m=0;
            for(int i=0;i<26;i++){
                l.append(c[i]/2, 'a'+i);
                if(c[i]&1) m = 'a'+i;
            }
            string r = l;
            reverse(r.begin(), r.end());
            return l + (m ? string(1, m) : "") + r;
        }
    };

// 3518 Smallest Palindromic Rearrangement II

#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ull;
const ull TH = 1000001;
ull cmb(int n, int r) {
    if (r > n)
        return 0;
    ull res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
        if (res > TH)
            return TH;
    }
    return res;
}
ull calc(vector<int>& a, int tot) {
    ull res = 1;
    for (int i = 0; i < 26; i++) {
        if (a[i]) {
            res *= cmb(tot, a[i]);
            if (res > TH)
                res = TH;
            tot -= a[i];
        }
    }
    return res;
}
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        string prelunthak = s;
        int f[26] = {0};
        for (char c : s)
            f[c - 'a']++;
        char m = '\0';
        int h[26] = {0}, tot = 0;
        for (int i = 0; i < 26; i++) {
            h[i] = f[i] / 2;
            tot += h[i];
            if (f[i] % 2 == 1)
                m = 'a' + i;
        }

        vector<int> a(h, h + 26);
        ull totc = calc(a, tot);
        if (k > totc)
            return "";
        string r = "";
        while (tot) {
            for (int i = 0; i < 26; i++) {
                if (a[i]) {
                    a[i]--;
                    ull w = calc(a, tot - 1);
                    if (w >= (ull)k) {
                        r.push_back('a' + i);
                        tot--;
                        break;
                    } else {
                        k -= w;
                        a[i]++;
                    }
                }
            }
        }
        string rr = r;
        reverse(rr.begin(), rr.end());
        return r + (m ? string(1, m) : "") + rr;
    }
};