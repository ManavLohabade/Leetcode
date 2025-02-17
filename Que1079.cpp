// Letter Tile Possibilities

class Solution {
    public:
        int count=0;
        void sol(string s,vector<int>& vis,unordered_map<string,int>& mp,string ans,int n,int a){
            if(a>=1){
                if(mp.find(ans)==mp.end()){
                    count++;
                    mp[ans]=1;
                }
                if(ans.length()==n){
                    return;
                }
            }
            for(int i=0;i<s.length();i++){
                if(vis[i]==0){
                ans+=s[i];
                vis[i]=1;
                a++;
                sol(s,vis,mp,ans,n,a);
                a--;
                ans.pop_back();
                vis[i]=0;
                }
            }
        }
        int numTilePossibilities(string s) {
            vector<int> vis(s.length(),0);
            unordered_map<string,int> mp;
            string ans="";
            int n=s.length();
            sol(s,vis,mp,ans,n,0);
            return count;
        }
    };