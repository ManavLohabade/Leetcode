// Minimum Operations to make array value equal to K 

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            for(int i=0;i<nums.size();i++){
                if(nums[i]<k){
                    return -1;
                }
            }
            unordered_set <int> st;
            for(int i=0;i<nums.size();i++){
                st.insert(nums[i]);
            }
            if(st.find(k)== st.end()){
                return st.size();
            }
            return (st.size()-1);
        }
    };