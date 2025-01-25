// Make Lexicographically Smallest Array by Swapping Elements

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

  int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(), v.end());

        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        unordered_map<int, list<int>> groupToList;

        numToGroup[v[0]] = groupNum;
        groupToList[groupNum].push_back(v[0]);

        for (int i = 1; i < n; i++) { 
            if (abs(v[i] - v[i - 1]) > limit) {
                groupNum += 1;
            }
            numToGroup[v[i]] = groupNum;
            groupToList[groupNum].push_back(v[i]);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int grp = numToGroup[num];
            res[i] = groupToList[grp].front();
            groupToList[grp].pop_front();
        }

        return res;

//  BRUTE FORCE APPROACH -> 0(N^3)        
        // int n = nums.size();
        // for(int i=0;i<n;i++)
        // {
        //     while(1)
        //     {
        //         int small = nums[i];
        //         int idx = -1;

        //         for(int j=i+1;j<n;j++)
        //         {
        //             if(abs(nums[i] - nums[j] <= limit))
        //             {
        //                 if(nums[j] < small)
        //                 {
        //                     small = nums[j];
        //                     idx = j;
        //                 }
        //             }
        //         }
        //         if(idx!=-1)
        //         swap(nums[i], nums[idx]);
        //         else
        //         break;
        //     }
        // }

        // return nums;
    }
};