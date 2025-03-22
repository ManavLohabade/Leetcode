// Count the number of complete components

class Solution {
public:
    int countCompleteComponents(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        enum {VERTEX_1, VERTEX_2};
        for(const auto& edge : edges) {
            graph[edge[VERTEX_1]].push_back(edge[VERTEX_2]);
            graph[edge[VERTEX_2]].push_back(edge[VERTEX_1]);
        }

        vector<bool> visited(n);

        auto get_vertices = [&](int vertex) {
            queue<int> vertices;
            vertices.push(vertex);
            visited[vertex] = true;

            vector<int> ret;
            while(!vertices.empty()) {
                ret.push_back(vertices.front());
                vertices.pop();
                for(auto next : graph[ret.back()]) {
                    if(visited[next]) continue;
                    vertices.push(next);
                    visited[next] = true;
                }
            }

            return ret;
        };

        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(visited[i]) continue;

            vector<int> subgraph = get_vertices(i);
            const int connects = size(subgraph) - 1;

            bool is_complite = true;
            for(const auto vertex : subgraph) {
                if(size(graph[vertex]) != connects) {
                    is_complite = false;
                    break;
                }
            }
            count += is_complite;
        }

        return count;
    }
};