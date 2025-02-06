//kids with the greatest number of candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int e) {
        vector<bool> r(candies.size());
        int m=*max_element(candies.begin(), candies.end());
        for(int i=0;i<candies.size();i++)
        {
            if((candies[i]+e)>=m)
                r[i]=true;
            else
                r[i]=false;
        }
        return r;
    }
};