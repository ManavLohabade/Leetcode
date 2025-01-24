// Count Servers that Communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        vector<int> rows(r, 0);
        vector<int> cols(c, 0);
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j]==1){
                    rows[i]+=1;
                    cols[j]+=1;
                }
            }
        }
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j]==1 && (rows[i]>1 || cols[j]>1)) ans++;
            }
        }
        return ans;
    }
};