// Minimum Time to repair Cars 

class Solution {
    public:
        bool checker(vector<int>& ranks, long long mid, int cars){
            int index = 0;
            long long countCar = 0;
    
            while(index < ranks.size()){
                countCar += sqrt(mid/ranks[index]);
                index++;
                if (countCar >= cars) return true;
            }
    
            // if(countCar >= cars) return true;
            // else return false;
            return countCar >= cars;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            long long maxEle = *max_element(ranks.begin(),ranks.end());
            long long right = maxEle * cars * cars;
    
    
            // cout<<right<<" ";
            long long left = 1;
            long long ans = 0;
    
            while(left <= right){
                long long mid = left + ((right-left)/2);
                // cout<<mid<<endl;
    
                if(checker(ranks,mid,cars)){
                    ans = mid;
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
    
            return ans;
    
        }
    };