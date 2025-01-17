// Find Kth Bit in Nth Binary String

class Solution {
public:
    char findKthBit(int n, int k) {
        int arr[21] = {1};
        int count = 0;
        for (int i=1; i<21; i++) arr[i] = 2*arr[i-1];
        for (int i=20; i>=0; i--) {
            if (arr[i] > k) continue;
            if (arr[i] == k) {
                if (k == 1) {
                    if (count%2 == 1) return '1';
                    return '0';
                }
                if (count%2 == 1) return '0';
                return '1';
            }
            count++;
            k = 2*arr[i]-k;
        }
        return '1';
    }
};