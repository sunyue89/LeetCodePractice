/*Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<vector<int>> area(matrix.size(),vector<int> (matrix[0].size()));

        for(int i=0;i<matrix.size();++i){
            area[i][0] = matrix[i][0]=='1';
        }
        for(int j=0;j<matrix[0].size();++j){
            area[0][j] = matrix[0][j]=='1';
        }
        for(int i=1;i<matrix.size();++i){
            for(int j=1;j<matrix[0].size();++j){
                if(matrix[i][j]=='1'){
                    area[i][j] = min(min(area[i-1][j-1],area[i][j-1]),area[i-1][j])+1;
                }else{
                    area[i][j] = 0;
                }
            }
        }
        int max = 0;
        for(int i = 0; i<area.size(); ++i){
            for(int j =0; j<area[0].size(); ++j){
                if (area[i][j] > max) 
                    max = area[i][j] ;
            }
        }
        return max*max;
    }
};

