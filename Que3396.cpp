// Minimun Number if Operations to make elements in array distinct

class Solution {
    public:
    
        // Better approach with O(n) TC and SC
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            unordered_set<int> st;
    
            for(int i = n-1;i>=0;i--){
                if(st.count(nums[i])){
                    return ceil((i+1)/3.0);
                }
                st.insert(nums[i]);
            }
            return 0;
        }
    
    
        /*
    
        // TC = O(n^2)
        // SC = O(n)
        bool check(int index,vector<int>& nums){
            unordered_set<int> st;
    
            for(int i = index;i<nums.size();i++){
                if(st.count(nums[i]) == 1){
                    return false;
                }
                st.insert(nums[i]);
            }
            return true;
        }
    
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            int operations = 0;
            for(int i = 0;i<n;i+=3){
                if(check(i,nums) == true){
                    return operations;
                }
                operations++;
            }
            return operations;
        }
    
        */
    };