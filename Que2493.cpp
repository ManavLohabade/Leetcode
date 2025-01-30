// Divide Nodes into the maximum number of Groups

class Solution {
public:
    unordered_map<int, vector<int>> adj;

    bool checkBipartite(vector<int>& color, int i, int currColor){
        color[i] = currColor;

        for(int& v : adj[i]){
            if(color[i] == color[v]) return false;
            if(color[v] == -1 && !checkBipartite(color, v, 1-currColor)) return false;
        }

        return true;
    }

    int bfs(int currNode, int n){
        vector<bool> visited(n, false);
        visited[currNode] = true;
        queue<int> que;
        int level = 1;

        que.push(currNode);
        while(!que.empty()){
            int size = que.size();
            while(size--){
                int value = que.front();
                que.pop();

                for(int& v : adj[value]){
                    if(!visited[v]){
                        visited[v] = true;
                        que.push(v);
                    }
                }
            }
            level ++;
        }
        return level-1;
    }

    int getMaxGroupGraph(int i, vector<bool>& visited, vector<int>& levels){
        visited[i] = true;
        int maxGroup = levels[i];
        for(int value : adj[i]){
            if(!visited[value]){
                visited[value] = true;
                maxGroup = max(maxGroup, getMaxGroupGraph(value, visited, levels));
            }
        }
        return maxGroup;
    }


    int magnificentSets(int n, vector<vector<int>>& edges) {
        
        // int n = edges.size();
        for(auto edge : edges){
            int u = edge[0]-1; // -1 for making 0 base indexing...
            int v = edge[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // check graph is bipartite or not 
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] == -1 && !checkBipartite(color, i, 1)) return -1;
        }

        // BFS to find max no of group form each node
        vector<int> levels(n, 0);
        for(int i=0; i<n; i++){
            levels[i] = bfs(i, n);
        }

        // for find max in all graph
        vector<bool> visited(n, false);
        int maxGroupEachGraph = 0;
        for(int i=0; i<n; i++){
            if(visited[i] == false){
                maxGroupEachGraph += getMaxGroupGraph(i, visited, levels);
            }
        }

        return maxGroupEachGraph;

    }
};