// Minimum Cost for tickets

class Solution {
    public:
       int mincostTickets(vector<int>& days, vector<int>& costs) {
           int n=days.size();
           vector<int>dp(n+1,INT_MAX);
           dp[n]=0;
           for(int i=n-1;i>=0;i--){
               int o1= costs[0] + dp[i+1];
               int k;
               for(k=i;k<n && days[k]<days[i]+7;k++);
               int o2= costs[1] + dp[k];
               for(k=i;k<n && days[k]<days[i]+30;k++);
               int o3 = costs[2] + dp[k];
               dp[i]=min(o1,min(o2,o3));
           }
           return dp[0];
       }
    };