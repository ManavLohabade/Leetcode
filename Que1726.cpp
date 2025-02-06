// Tuple with Same Products 

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int temp = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                mp[nums[i]*nums[j]]++;
                temp = max(temp,mp[nums[i]*nums[j]]);
            }
        }
        vector<long long>fact(temp+1,1);
        for(int i=1; i<=temp; i++){
            fact[i] = fact[i-1]*i;
        }
        int ans = 0;
        for(auto &i:mp){
            if(i.second>=2){
                ans+= 8*(fact[i.second]/fact[i.second-2])/2;
            }
        }
        return ans;
    }
};