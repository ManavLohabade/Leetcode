// Closest Prime Number in Range

class Solution {
    public:
        bool isPrime(int n) {
            if (n < 2) return false;
            if (n == 2 || n == 3) return true;
            if (n % 2 == 0 || n % 3 == 0) return false;
            for (int i = 5; i * i <= n; i += 6) {
                if (n % i == 0 || n % (i + 2) == 0) return false;
            }
            return true;
        }
        
        vector<int> closestPrimes(int left, int right) {
            int prev = -1, num1 = -1, num2 = -1;
            int minDiff = INT_MAX;
            
            for (int i = left; i <= right; i++) {
                if (isPrime(i)) {
                    if (prev != -1 && (i - prev < minDiff)) {
                        num1 = prev;
                        num2 = i;
                        minDiff = i - prev;
                    }
                    prev = i;
                }
            }
            
            if (num1 == -1) return {-1, -1};
            return {num1, num2};// code with prince
        }
    };