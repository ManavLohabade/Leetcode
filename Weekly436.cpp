// Sort matrix by diagonals 

class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            
            // Sort bottom-left triangle diagonals in non-increasing order
            for (int i = 0; i < n; i++) {
                vector<int> diag;
                int x = i, y = 0;
                while (x < n && y < n) {
                    diag.push_back(grid[x][y]);
                    x++;
                    y++;
                }
                sort(diag.rbegin(), diag.rend());
                x = i, y = 0;
                for (int val : diag) {
                    grid[x][y] = val;
                    x++;
                    y++;
                }
            }
    
            for (int j = 1; j < n; j++) {
                vector<int> diag;
                int x = 0, y = j;
                while (x < n && y < n) {
                    diag.push_back(grid[x][y]);
                    x++;
                    y++;
                }
                sort(diag.begin(), diag.end());
                x = 0, y = j;
                for (int val : diag) {
                    grid[x][y] = val;
                    x++;
                    y++;
                }
            }
    
            return grid;
        }
    };