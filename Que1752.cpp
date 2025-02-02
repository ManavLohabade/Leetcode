// Check if array is sorted and rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int d=0,a=nums[0],c=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]) {
                d=nums[i-1];
                c++;
            }
           if(d!=0){
            if(nums[i]>a) return false;
            if(c>1) return false;
           }
        }
        
        return true;
    }
};