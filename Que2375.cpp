// Construct smallest number from DI String

class Solution {
    public:
    
        bool matchesPattern(string &nums, string &pattern){
            for(int i = 0; i<pattern.length(); i++){
                if((pattern[i] == 'I' && nums[i] > nums[i+1]) || (pattern[i] == 'D' && nums[i] < nums[i+1])){
                    return false;
                }
            }
    
            return true;
        }
    
    
        string smallestNumber(string pattern) {
            // int n = pattern.length();
    
            // string nums = "";
    
            // for(int i = 1; i<= n+1 ; i++){
            //       nums.push_back(i+ '0');
            // }
    
            // while(!matchesPattern(nums, pattern)){
            //     next_permutation(begin(nums), end(nums));
            // }
    
            // return nums;
    
            int n = pattern.length();
            string num = "";
    
            int counter = 1;
            stack<int> st;
            for(int i=0; i<=n ;i++){
                st.push(counter + '0');
                counter++;
    
                if(i == n || pattern[i]=='I'){
                    while(!st.empty()){
                        num += st.top();
                        st.pop();
                    }
                }
            }
    
            return num;
        }
    };