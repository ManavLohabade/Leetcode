// First Completely Painted Row & Column

class Solution {
    #define pii pair<int,int>
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        //Step-1: Create lookup for each value in matrix
        vector<pii> lookup(m*n+1);//Stores x,y coordinate for each element in matrix
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                lookup[mat[i][j]]=make_pair(i,j);

        //Step-2: Find earliest row or col painted
        vector<int> row_count(m,0);
        vector<int> col_count(n,0);

        for(int i=0;i<m*n;++i){
            pii coordinate = lookup[arr[i]];
            int x = coordinate.first;
            int y = coordinate.second;
            
            row_count[x]++;
            col_count[y]++;
            if(row_count[x]==n or col_count[y]==m)
                return i;
        }
        return 0;
    }
};