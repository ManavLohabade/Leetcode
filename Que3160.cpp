// Find the number of distinct colors among the balls 

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        int n = queries.size();
        unordered_map<int,int> map;
        unordered_map<int,int> freq;
        vector<int> ans;
        
        for(auto & q :queries){
            int x = q[0];
            int y = q[1];

            if(map.find(x) != map.end()){
                freq[map[x]]--;
                if(freq[map[x]] == 0){
                    freq.erase(map[x]);
                }
            }
            map[x] = y;
            freq[y]++;
            ans.push_back(freq.size());
        }

        return ans;
    }
};