/*In a N x N grid representing a field of cherries, each cell is one of three possible integers.

 

0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.
 

Your task is to collect maximum number of cherries possible by following the rules below:

 

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
 

 

Example 1:

Input: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
Output: 5
Explanation: 
The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
 

Note:

grid is an N by N 2D array, with 1 <= N <= 50.
Each grid[i][j] is an integer in the set {-1, 0, 1}.
It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.
 

Last Submission
Last Saved Code*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        dp[0][0] = grid[0][0];
        //DP with back tracking for forward pick-up
        for(int k=1;k<2*n-1;++k){
            for(int i=n-1;i>=0;--i){
                for(int p=n-1;p>=0;--p){
                    int j=k-i,q=k-p;
                    if (j < 0 || j >= n || q < 0 || q >= n || grid[i][j] < 0 || grid[p][q] < 0) {
                        dp[i][p] = -1;
                        continue;
                    }
                    if (i > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p]);
                    if (p > 0) dp[i][p] = max(dp[i][p], dp[i][p - 1]);
                    if (i > 0 && p > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);
                    if (dp[i][p] >= 0) dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0);
                }
            }
        }
        return max(dp[n-1][n-1],0);
    }
};
