// find all possible recipes from given supplies 

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes,
                                      vector<vector<string>>& ingredients,
                                      vector<string>& supplies) {
            
            vector<string> out;
            unordered_map<string, unordered_set<string>> AL;
            unordered_map<string, int> id;
            for (int i = 0; i < recipes.size(); ++i) {
                id[recipes[i]] += ingredients[i].size();
                for (auto in : ingredients[i]) {
                    AL[in].insert(recipes[i]);
                }
            }
    
            deque<string> DQ(supplies.begin(), supplies.end());
            while (!DQ.empty()) 
            {
                auto nd = DQ.front(); DQ.pop_front();
                for(auto nb : AL[nd])
                {
                    if(--id[nb] == 0)
                    {
                        DQ.push_back(nb);
                        out.push_back(nb);
                    }
                }
            }
    
            return out;
        }
    };