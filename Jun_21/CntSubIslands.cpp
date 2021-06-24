/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

 

Example 1:


Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
Example 2:


Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
 

Constraints:

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.
*/

class Solution {
public:
    bool con = true;
    vector<vector<int>> sur = {{-1,0},{1,0},{0,-1},{0,1}};
    
    void DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& vis, int i, int j, int m, int n){

        if(!vis[i][j]){
            vis[i][j] = true;
            if(!grid1[i][j])
                con = false;
            for(auto& s:sur){
                if(i+s[0] >=0 && i+s[0] <m && j+s[1] >=0 && j+s[1] <n && grid2[i+s[0]][j+s[1]]){
                    if(!grid1[i+s[0]][j+s[1]])
                        con = false;
                    DFS(grid1,grid2,vis,i+s[0],j+s[1],m,n);
                }
            }
        }
        return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //dfs in grid2, cross check grid1, till grid2 is done, if all in, add
        int m = grid2.size();
        int n = grid2[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n));
        int ct = 0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid2[i][j] && !vis[i][j]){
                    con = true;
                    DFS(grid1,grid2,vis,i,j,m,n);
                    if(con)
                        ct++;
                }
            }
        }
        return ct;
    }
};
