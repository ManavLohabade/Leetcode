// Map of Highest Peak

class Solution {
public:

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

vector<vector<int>> highestPeak(vector<vector<int>>& is) {
    queue<pair<pair<int, int>, int>> q; // Queue to perform BFS  ({{row,col},height});
    vector<vector<int>> vis(is.size(), vector<int>(is[0].size(), -1)); // Initialize visited array with -1

    // Push all water cells into the queue with height 0
    for (int i = 0; i < is.size(); i++) {
        for (int j = 0; j < is[0].size(); j++) {
            if (is[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 0; // Mark water cells as visited with height 0
            }
        }
    }

    // BFS to calculate heights
    while (!q.empty()) {
        auto it = q.front();
        int row = it.first.first;
        int col = it.first.second;
        int curr = it.second;
        q.pop();

        // Visit all 4 neighbors
        for (int i = 0; i < 4; i++) {
            int newr = row + di[i];
            int newc = col + dj[i];

            // Check bounds and if the cell is unvisited
            if (newr >= 0 && newr < is.size() && newc >= 0 && newc < is[0].size() && vis[newr][newc] == -1) {
                vis[newr][newc] = curr + 1; // Assign height to the neighbor
                q.push({{newr, newc}, curr + 1}); // Push neighbor into the queue
            }
        }
    }

    return vis;
}

};