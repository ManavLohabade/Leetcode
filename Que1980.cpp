// Find Unique Binary String 

class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            int n=nums.size();
            string result="";
            for(int i=0;i<n;i++){
                char a = (nums[i][i]=='1')? '0':'1';
                result.push_back(a);
            }
            return result;
        }
    };