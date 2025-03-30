// Apply Operations to maximize Score

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n=s.size();
            unordered_map<char,int>mp;
            for(int i=0;i<n;i++)
            {
                mp[s[i]]=i;
            }
            int size=0;
            int end=0;
            vector<int>ans;
            for(int i=0;i<n;i++)
            {
                if(mp[s[i]]>end)
                {
                    end=mp[s[i]];
                }
                size++;
                if(i==end)
                {
                    ans.push_back(size);
                    size=0;
                }
            }
            return ans;
        }
    };