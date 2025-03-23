// Number of Ways to arrive Destination 

class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            const int MOD = 1e9 + 7;
            vector<vector<pair<int, int>>> graph(n);
            for (auto& road : roads) {
                int u = road[0], v = road[1], t = road[2];
                graph[u].emplace_back(v, t);
                graph[v].emplace_back(u, t);
            }
    
            vector<long long> dist(n, LLONG_MAX);
            vector<int> ways(n, 0);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    
            dist[0] = 0;
            ways[0] = 1;
            pq.emplace(0, 0);
    
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
    
                if (d > dist[u]) continue;
    
                for (auto& [v, t] : graph[u]) {
                    long long newDist = d + t;
                    if (newDist < dist[v]) {
                        dist[v] = newDist;
                        ways[v] = ways[u];
                        pq.emplace(newDist, v);
                    } else if (newDist == dist[v]) {
                        ways[v] = (ways[v] + ways[u]) % MOD;
                    }
                }
            }
    
            return ways[n - 1];
        }
    };