// Minimum Operation to make a uni-value gird 

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int>v;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[i].size();j++){
                    v.push_back(grid[i][j]);
                }
            }
            sort(v.begin(), v.end());
            int rem=v[0]%x;
            for(int i=0;i<v.size();i++){
                if(v[i]%x!=rem)
                return -1;
            }
            int medium=v[v.size()/2];
           int min_op=0;
            for(int i=0;i<v.size();i++){
              min_op+=abs(v[i]-medium)/x;
            }
            return min_op;
        }
    };