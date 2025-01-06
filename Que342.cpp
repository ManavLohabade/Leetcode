// Power of Four

class Solution {
public:
    bool isPowerOfFour(int n) {
     for(int i=0;i<31;i++){
            long long pow = powl(4,i);
            if (pow==n){
                return true;
            }
        }
        return false;
    }
};