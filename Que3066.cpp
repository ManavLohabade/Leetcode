// Minimum Operations to exceed threshold value II

#include <bits/stdc++.h>
using namespace std;
#define ll long long  // Define ll as long long

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq; // Min heap
        int op = 0;

        for (int num : nums) {
            pq.push(num); // Push elements as long long
        }

        while (pq.size() >= 2) {
            ll fis = pq.top(); pq.pop();
            ll sec = pq.top(); pq.pop();
            
            if (fis >= k  ) break; 
            
            pq.push(fis* 2LL + sec);
            op++;
        }

        return op;
    }
};