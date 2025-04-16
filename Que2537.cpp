// Count tthe Number of Good Subarrays

class Solution {
    #define ll long long 
public:
    long long countGood(vector<int>& nums, int k) {
       ll n=nums.size();
       ll l=0,r=0;
       ll res=0;
       unordered_map<ll,ll> freq;
       ll equalPairs=0;

       while(l<n){
        while(r<n && equalPairs<k){
            freq[nums[r]]++;
            if(freq[nums[r]]>=2)
             equalPairs+= freq[nums[r]]-1;
            r++;
        }
        if(equalPairs>=k)
         res+= n-r+1;

        freq[nums[l]]--;
        if(freq[nums[l]]>0)
           equalPairs-= freq[nums[l]];
        l++;
       }
       return res;
    }
};