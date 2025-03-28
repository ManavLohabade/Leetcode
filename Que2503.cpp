// Maximum Number of points from rif Queries 

class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size(), n = grid[0].size();
            int k = queries.size();
            vector<pair<int, int>> indexed_queries;
            for(int i = 0; i < k; i++){
                indexed_queries.emplace_back(queries[i], i);
            }
            sort(indexed_queries.begin(), indexed_queries.end());
            vector<int> answer(k);
            int ans = 0;
            vector<vector<int>> visited(m, vector<int>(n, 0));
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
            pq.emplace(grid[0][0], make_pair(0, 0));
            visited[0][0] = 1;
            for(int index = 0; index < k; index++) {
                while(!pq.empty() && pq.top().first < indexed_queries[index].first){
                    int val = pq.top().first;
                    int i = pq.top().second.first, j = pq.top().second.second;
                    pq.pop();
                    ans++;
                    add_queue(grid, visited, pq, i, j);
                }
                answer[indexed_queries[index].second] = ans;
            }
            return answer;
        }
        void add_queue(vector<vector<int>>& grid, vector<vector<int>>& visited, priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>& pq, int i, int j){
            int m = grid.size(), n = grid[0].size();
            if(i >= 1 && visited[i-1][j] == 0){
                pq.emplace(grid[i-1][j], make_pair(i-1, j));
                visited[i-1][j] = 1;
            }
            if(j >= 1 && visited[i][j-1] == 0){
                pq.emplace(grid[i][j-1], make_pair(i, j-1));
                visited[i][j-1] = 1;
            }
            if(i+1 < m && visited[i+1][j] == 0){
                pq.emplace(grid[i+1][j], make_pair(i+1, j));
                visited[i+1][j] = 1;
            }
            if(j < n-1 && visited[i][j+1] == 0){
                pq.emplace(grid[i][j+1], make_pair(i, j+1));
                visited[i][j+1] = 1;
            }
        }
    };