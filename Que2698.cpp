// Find the pusnishment number of an integer 

class Solution {
    public:
        bool isP(int startInd, int sum, string stringNum, int target){
            if(startInd == stringNum.size()) return sum == target;
            if(sum>target) return false;
            bool partitionFound = false;
            for(int i = startInd; i < stringNum.size(); i++){
                string curString = stringNum.substr(startInd, i - startInd+1);
                int addend = stoi(curString);
                partitionFound = partitionFound || isP(i+1, sum+addend, stringNum, target);
                if(partitionFound) return true;
            }
            return false;
        }
    
        int punishmentNumber(int n) {
            int res = 0;
            for (int i = 1; i <= n; i++) {
                int squareNum = i * i;
                string stringNum = to_string(squareNum);
                if(isP(0,0,stringNum,i)){
                    res+=squareNum;
                }
            }
            return res;
        }
    };