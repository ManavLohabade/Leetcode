// Maximum Candies Allocated to K Children 

class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            long long l = 1, r = *max_element(candies.begin(), candies.end()), res = 0;
            while (l <= r) {
                long long m = (l + r) / 2, count = 0;
                for (int c : candies) 
                    count += c / m;
                if (count >= k) 
                    res = m, l = m + 1;
                else 
                    r = m - 1;
            }
            return res;
        }
    };