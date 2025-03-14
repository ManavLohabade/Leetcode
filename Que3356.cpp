// Zero Array Transformation II

// 5 testcase not passed
#include <vector>
using namespace std;

class Solution {
public:
    bool checkAllZero(vector<int>& nums) {
        for (int num : nums) {
            if (num != 0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int Q = queries.size();
        int N = nums.size();

        for (int i = 0; i < Q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][2];
            for (int j = l; j <= r; j++) {
                nums[j] = max(0, nums[j] - v);
            }

            if (checkAllZero(nums)) {
                return i + 1; 
            }
        }

        return -1; 
    }
};


// All Passed 
class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size(), m = queries.size();
            int l = 0, r = m, result = -1;
            if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return 0;
            vector<int> pre(n + 1, 0);
            while(l<r) {
              int mid = l + (r-l)/2;
              fill(pre.begin(), pre.end(), 0);
              for(int i=0; i<=mid; i++) {
                pre[queries[i][0]]+=queries[i][2];
                pre[queries[i][1]+1]-=queries[i][2];
              }
              bool valid = true;
              int prefixSum = 0;
              for (int i = 0; i < n; i++) {
                prefixSum += pre[i];
                if (prefixSum < nums[i]) {
                  valid = false;
                  break;
                }
              }
              if (valid) {
                result = mid + 1;
                r = mid;
              } else {
                l = mid + 1;
              }
            }
            return result;
        }
    };