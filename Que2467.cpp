// Most Profitable Path in a tree

class Solution {
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();
            vector<vector<int>> tree(n);
            vector<int> parent(n);
            for(auto& edge: edges) {
                tree[edge[0]].push_back(edge[1]);
                tree[edge[1]].push_back(edge[0]);
            }
            dfs(0, -1, tree, parent);
            int res = INT_MIN;
            solve(0, bob, 0, amount, tree, parent, res);
            return res;
        }
    private:
        void dfs(int node, int p, vector<vector<int>>& tree, vector<int>& parent) {
            parent[node] = p;
            for(int child: tree[node]) {
                if(child != p) {
                    dfs(child, node, tree, parent);
                }
            }
        }
        void solve(int alice, int bob, int income, vector<int>&amount, vector<vector<int>>& tree, vector<int>& parent, int &res) {
            income += amount[alice] / (1 + (int)(alice == bob));
            int temp = amount[bob];
            amount[bob] = 0;
            if(alice != 0 && tree[alice].size() == 1) {
                res = max(res, income);
            }
            int bob_parent = (bob == 0 ? 0 : parent[bob]);
            for(int child: tree[alice]) {
                if(child != parent[alice]) {
                    solve(child, bob_parent, income, amount, tree, parent, res);
                }
            }
            amount[bob] = temp;
        }
    };
    