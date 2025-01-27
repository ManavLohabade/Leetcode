// 1462. Course Schedule IV

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reach(numCourses,vector<bool>(numCourses, false));
        for (const auto& prereq : prerequisites) {
            int a = prereq[0];
            int b = prereq[1];
            reach[a][b] = true; 
        }
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                }
            }
        }
        vector<bool> result;
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            result.push_back(reach[u][v]);
        }
        return result;
    }
};