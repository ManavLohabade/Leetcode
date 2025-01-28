// Decode String

class Solution {
public:
    string decodeString(string s) {
        const int m = s.size();
        string ans = "";string temp = "";int mul = 0;
        stack<int> num;stack<string> st;
        for(int i=0;i<m;++i){
            if(s[i]>='0'&&s[i]<='9'){mul=mul*10+(s[i]-'0');}
            else if(s[i]=='['){st.push(ans);num.push(mul);mul=0;ans="";}
            else if(s[i]==']'){
                temp=ans;
                for(int j=1;j<num.top();++j){ans=ans+temp;}
                num.pop();ans=st.top()+ans;st.pop();
            }
            else{ans.push_back(s[i]);}
        }
        return ans;
    }
};