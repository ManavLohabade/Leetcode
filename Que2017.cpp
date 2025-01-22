// Grid Game

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        vector<long long>v1;
        vector<long long>v2;
        long long sum1=0;
        long long sum2=0;
        for(int i=0;i<grid[0].size();i++){
            sum1+=grid[0][i];
            v1.push_back(sum1);
            sum2+=grid[1][i];
            v2.push_back(sum2);

        }
        long long mini=LLONG_MAX;
        long long n=grid[0].size();

        for(int i=0;i<grid[0].size();i++){
            long long m=(i==0)?0:v2[i-1];
            mini=min(mini,max(v1[n-1]-v1[i], m));
        }

        return mini;
    }
};