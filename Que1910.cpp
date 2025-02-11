// Remove all occurrences of a substring

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            stack <char> st;
            int np = part.size();
            int ns = s.size();
            string ans = "", temp = "";
            for(int i=0;i<ns;i++)
            {
                st.push(s[i]);
                
                if(st.size() >= np)
                {
                    temp = "";
                    for(int j=0;j<np;j++)
                    {
                        temp = st.top() + temp;
                        st.pop();
                    }
                    if(temp != part)
                    {
                        for(char& c : temp)
                        {
                            st.push(c);
                        }
                    }
                }
            }
    
            while(st.size()>0)
            {
                ans = st.top() + ans;
                st.pop();
            }
    
            return ans;
        }
    };