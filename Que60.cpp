// Permutation Sequence

class Solution {
public:
    void rightRotate(string &s, int i, int j){
        char temp = s[j];

        for(int x=j; x>i; x--){
            s[x] = s[x-1];
        }

        s[i] = temp;
    }

    void leftRotate(string &s, int i, int j){
        char temp = s[i];

        for(int x=i; x<j; x++){
            s[x] = s[x+1];
        }

        s[j] = temp;
    }

    void permute(string &s, int i, vector<string> &ans){
        
        if(i==s.length()){
            ans.push_back(s);
            return;
        }

        for(int j=i; j<s.length(); j++){
            rightRotate(s,i,j);
            permute(s,i+1,ans);
            leftRotate(s,i,j);
        }
    }

    string getPermutation(int n, int k) {
        string s = "";

        for(int i=1;i<=n;i++){
            s += to_string(i);
        }

        vector<string> ans;

        permute(s,0,ans);
        return ans[k-1];
    }
};