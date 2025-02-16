// Construct the Lexicographically largest valid sequence 

class Solution {
    public:
        bool found=false;
        void solve(int index,vector<int>&ans,vector<int>&path,vector<int>&freq,int n)
        {
         if(found==true)
         return;
    
         if(index==2*n-1)
         {
            found=true;
            ans=path;
            return;
         }
         if(path[index]!=-1){
         solve(index+1,ans,path,freq,n);
         return ;}
    
         for(int i=n;i>=1;i--)
         {
            if(freq[i]==0)
            continue;
    
            if(i!=1&&index+i<2*n-1&&path[index+i]==-1)
            {
                path[index]=i;
                path[index+i]=i;
                freq[i]=0;
                solve(index+1,ans,path,freq,n);
                path[index]=-1;
                path[index+i]=-1;
                freq[i]=2;
            }
            else if(i==1){
                path[index]=1;
                freq[1]=0;
                solve(index+1,ans,path,freq,n);
                path[index]=-1;
                freq[1]=1;
            }
         }
    
        }
        vector<int> constructDistancedSequence(int n) {
            vector<int>freq(n+1,2);
            freq[1]=1;
            freq[0]=0;
            vector<int>ans(2*n-1);
            vector<int>path(2*n-1,-1);
            solve(0,ans,path,freq,n);
            return ans;
    
        }
    };