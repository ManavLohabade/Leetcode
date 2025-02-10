// Clear Digits 

class Solution {
    public:
        string clearDigits(string s) {
            int n=s.length();
            string ans="";
            stack<char>st;
            for(int i=0;i<n;i++){
                if(isdigit(s[i])){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
            if(st.empty()) return "";
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };