// Number of Substrings Containing All Three Characters

class Solution {
    public:
        int numberOfSubstrings(string s) {
            vector<int>alphabetCount(3,0);
            int stringLength = s.length();
            int leftPtr = 0,rightPtr = -1, result = 0;
            bool everyElementPresent = false;
            alphabetCount[s[0]-'a']++;
            for(int i=1;i<stringLength;i++)
            {
                alphabetCount[s[i]-'a']++;
                rightPtr = i;
                if(s[leftPtr] == s[rightPtr])
                {
                    while(leftPtr<rightPtr && alphabetCount[s[leftPtr]-'a'] > 1)
                    {
                        alphabetCount[s[leftPtr]-'a'] --;
                        leftPtr++;
                    }
                }
    
                everyElementPresent = true;
                for(auto i:alphabetCount)
                {
                    if(i<1)
                    {
                        everyElementPresent = false;
                        break;
                    }
                }
                if(everyElementPresent)
                {
                    result += (leftPtr+1);
                }
                
            }
            return result;
        }
    };