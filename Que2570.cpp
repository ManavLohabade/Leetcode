// class Solution {
public:
vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    int i=0;
    int j=0;
    int k=0;
    vector<vector<int>>result;
    while(i<nums1.size()&&j<nums2.size())
    {
        if(nums1[i][0]<nums2[j][0])
        {
            result.push_back(nums1[i++]);
        }
        else if (nums1[i][0] == nums2[j][0]) {
            result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
            i++; j++;
        } 
        else
        {
            result.push_back(nums2[j++]);
        }
    }
    while (i < nums1.size()) result.push_back(nums1[i++]);
    while (j < nums2.size()) result.push_back(nums2[j++]);
    return result;
}
};