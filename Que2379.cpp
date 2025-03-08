// Minimum recolors to Get K consecutive black blocks

class Solution {
    public:
        int minimumRecolors(string blocks, int k) 
        {
            int i=0,j=0;
            int count=0;
            int mini=INT_MAX;
            while(j<blocks.length())
            {
                if(blocks[j]=='W')
                {
                    count++;
                }
                if(j-i+1<k)
                {
                    j++;
                }
                else if(j-i+1==k)
                {
                    mini=min(mini,count);
                    if(blocks[i]=='W')
                    count--;
                    i++;
                    j++;
                }
            } 
            return mini;       
        }
    };