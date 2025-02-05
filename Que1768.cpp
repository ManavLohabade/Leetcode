// Merge Strings Alternately

class Solution {
public:
    string mergeAlternately(string a, string b) {
        string c="";
        int n=a.length(),m=b.length();
        for(int i=0;i<max(n,m);i++)
        {
            if(i<n)
                c+=a[i];
            if(i<m)
                c+=b[i];
        }
        return c;
    }
};