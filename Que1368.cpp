// Minimun Cost to Make at Least One Valid Path in a Grid

class Solution {
public:
    bool isValid(int n, int m, int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1) {
            return 0;
        }
        vector<vector<int>> rew(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (isValid(n, m, x + 1, y)) {
                if (grid[x][y] == 3 && rew[x + 1][y] > cost) {
                    rew[x + 1][y] = cost;
                    pq.push({cost, {x + 1, y}});
                } else if (grid[x][y] != 3 && rew[x + 1][y] > cost + 1) {
                    rew[x + 1][y] = cost + 1;
                    pq.push({cost + 1, {x + 1, y}});
                }
            }
            if (isValid(n, m, x - 1, y)) {
                if (grid[x][y] == 4 && rew[x - 1][y] > cost) {
                    rew[x - 1][y] = cost;
                    pq.push({cost, {x - 1, y}});
                } else if (grid[x][y] != 4 && rew[x - 1][y] > cost + 1) {
                    rew[x - 1][y] = cost + 1;
                    pq.push({cost + 1, {x - 1, y}});
                }
            }
            if (isValid(n, m, x, y + 1)) {
                if (grid[x][y] == 1 && rew[x][y + 1] > cost) {
                    rew[x][y + 1] = cost;
                    pq.push({cost, {x, y + 1}});
                } else if (grid[x][y] != 1 && rew[x][y + 1] > cost + 1) {
                    rew[x][y + 1] = cost + 1;
                    pq.push({cost + 1, {x, y + 1}});
                }
            }
            if (isValid(n, m, x, y - 1)) {
                if (grid[x][y] == 2 && rew[x][y - 1] > cost) {
                    rew[x][y - 1] = cost;
                    pq.push({cost, {x, y - 1}});
                } else if (grid[x][y] != 2 && rew[x][y - 1] > cost + 1) {
                    rew[x][y - 1] = cost + 1;
                    pq.push({cost + 1, {x, y - 1}});
                }
            }
        }
        return rew[n - 1][m - 1];
    }
};