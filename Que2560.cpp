// House Robber IV

class Solution {
    public:
        bool valid(vector<int>& nums, int mid, int k){
            int cnt = 0;
            int n = nums.size();
            int i = 0;
            while(i < n){
                if(nums[i] <= mid){
                    i += 2;
                    cnt++;
                }else{
                    i += 1;
                }
            }
            return cnt >= k;
        }
        int minCapability(vector<int>& nums, int k) {
            int n = nums.size();
            int l = INT_MAX;
            int h = INT_MIN;
            for(auto it : nums){
                l = min(l, it);
                h = max(h, it);
            }
            cout<<l<<" "<<h;
            int ans = 0;
            while(l <= h){
                int mid = (l+h)/2;
                if(valid(nums, mid, k)){
                    ans = mid;
                    h = mid-1;
                }else{
                    l = mid+1;
                }
            }
            return ans;
        }
    };