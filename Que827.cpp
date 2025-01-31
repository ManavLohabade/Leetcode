// Making a Large Island

class DisjointSet {
public:
    vector<int> parent;
    vector<int> area;
    DisjointSet(int n) {
        parent.resize(n);
        area.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            area[i] = 1;
        }
    }
    int findParent(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]);
    }
    void unionSet(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU == rootV)
            return;
        if (area[rootU] < area[rootV]) {
            parent[rootU] = rootV;
            area[rootV] += area[rootU];
        } else {
            parent[rootV] = rootU;
            area[rootU] += area[rootV];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        DisjointSet ds(rows * cols);
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int u = (cols * i) + j;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols &&
                            grid[ni][nj] == 1) {
                            int v = cols * ni + nj;
                            ds.unionSet(u, v);
                        }
                    }
                }
            }
        }
        long long result = INT_MIN;
        bool hasZero = false;
        set<int> unique_Parents;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    hasZero = true;
                    long long ans = 0;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols &&
                            grid[ni][nj] == 1) {
                            int neighbor = cols * ni + nj;
                            int parent = ds.findParent(neighbor);
                            unique_Parents.insert(parent);
                        }
                    }
                    for (int parent : unique_Parents) {
                        ans += ds.area[parent];
                    }
                    unique_Parents.clear();
                    result = max(result, ans + 1);
                }
            }
        }
        if (!hasZero)
            return rows * cols;
        return result;
    }
};