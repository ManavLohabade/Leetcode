// Count days without meetings 

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            int n=meetings.size();
            sort(meetings.begin(),meetings.end());
            int ans=meetings[0][0]-1;
            int end=meetings[0][1];
            for(int i=1;i<n;i++)
            {
                    ans+=max(meetings[i][0]-end-1,0);
                    end=max(meetings[i][1],end);
            }
            return ans+days-end;
        }
    };