// Check if the grid can be cut into section 

class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            int cnt = 0;
            int size = rectangles.size();
    
            if (size < 3)
                return false; 
    
            // Horizontal check
    
            sort(rectangles.begin(), rectangles.end(), []
            (const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];   // Sort by y1
            });
            int end = rectangles[0][3]; 
            for (int i = 1; i < size; ++i) {
                int y1 = rectangles[i][1];
                int y2 = rectangles[i][3];
                if (y1 >= end) {
                    cnt++;
                    if (cnt > 1) break; // early exit 
                }
                end = max(end, y2);
            }
            if (cnt > 1) return true;
            
            // Vertical check
            cnt = 0;
            sort(rectangles.begin(), rectangles.end());
            end = rectangles[0][2]; 
            for (int i = 1; i < size; ++i) {
                int x1 = rectangles[i][0];
                int x2 = rectangles[i][2];
                if (x1 >= end) {
                    cnt++;
                    if (cnt > 1) break; //  early exit
                }
                end = max(end, x2);
            }
            return cnt > 1;
        }
    };