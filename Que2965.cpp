// Find Missing and Repeated values

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int> ans(2);
            int n = grid.size();
            unordered_map<int,int> umap;
            for(int i = 0 ; i < n*n; i++)
            {
                umap[i+1] = 0;
            }
            for(int i = 0 ; i < n;i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    umap[grid[i][j]]++;
                }
            }
            int a = -1;
            int b = -1;
            for(auto it : umap)
            {
                if(it.second == 2)
                {
                    a = it.first;
                }
                if(it.second == 0)
                {
                    b = it.first;
                }
            }
            ans[0] = a;
            ans[1] = b;
            return ans;
        }
    };