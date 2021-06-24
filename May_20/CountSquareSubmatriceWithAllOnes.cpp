/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

//[1 1 1]
//[1 1 1]
//[1 1 1]

//[1 2 3]
//[2 4 6]
//[3 6 9]


//  [0,1,1,1]
//  [1,1,1,1]
//  [0,1,1,1]

//  [0,1,2,3]
//  [1,3,5,7]
//  [1,4,7,10]


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        vector<vector<int>> sum(matrix.size(),vector<int>(matrix[0].size(),0));

        sum[0][0] = matrix[0][0];
        for(int i=1; i<sum.size(); ++i){
            sum[i][0] = sum[i-1][0] + matrix[i][0];
        }
        for(int j=1; j<sum[0].size(); ++j){
            sum[0][j] = sum[0][j-1] + matrix[0][j];
        }
        for(int j=1; j<matrix.size(); ++j){
            for(int k=1; k<matrix[0].size(); ++k){
                sum[j][k] = sum[j-1][k]+sum[j][k-1]-sum[j-1][k-1]+matrix[j][k];
                //cout<<sum[j][k]<<" ";
            }
            //cout<<j<<endl;
        }
        int sqr_lgt = min(matrix.size(),matrix[0].size());
        int ct = 0;
        for(int i=1; i<=sqr_lgt; ++i){
            for(int j=i-1; j<matrix.size(); ++j){
                for(int k=i-1; k<matrix[0].size(); ++k){
                    int tmp1 = 0;
                    int tmp2 = 0;
                    int tmp3 = 0;
                    if(j-i>=0){
                        tmp2 = sum[j-i][k];
                    }
                    if(k-i>=0){
                        tmp3 = sum[j][k-i];
                    }
                    if(j-i>=0 && k-i>=0){
                        tmp1 = sum[j-i][k-i];
                    }
                    if (sum[j][k] + tmp1 - tmp2 - tmp3 == i*i)
                        ct++;
                }
            }
        }
        return ct;
    }
};
