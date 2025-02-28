// Length of longest Fibonacci Subsequence

/*
class Solution {
public:
   int solve(int j,int k,vector<int>&arr,unordered_map<int,int>&mp,vector<vector<int>>&dp)
        {
            int tar = arr[k]-arr[j];
if(dp[k][j]!=-1) return dp[k][j];
            if(mp.count(tar) && mp[tar]<j)
            {
                    int i = mp[tar];
              return  dp[k][j] =  1+solve(i,j,arr,mp,dp);
            }

           return  dp[k][j] = 2;
        }
    
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
        }
int res=0;
        for(int j=1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
               int  len = solve(j,k,arr,mp,dp);
                if(len>=3)
                {
                    res = max(res,len);
                }
            }
        }

        return res; 
    }

     
};
*/

class Solution {
    public:
         int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
            vector<vector<int>>dp(n,vector<int>(n,2));
            unordered_map<int,int>mp;
          
    
            for(int i=0;i<n;i++)
            {
                mp[arr[i]]=i;
            }
    int res=0;
            for(int j=1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int tar = arr[k]-arr[j];
    
                    if(mp.count(tar) && mp[tar]<j)
                    {
                             int i = mp[tar];
                    dp[j][k] =  1+dp[i][j];
    
                    }
    
                    res = max(res,dp[j][k]);
                }
            }
    
            return res>=3?res:0;
    
         }
    };