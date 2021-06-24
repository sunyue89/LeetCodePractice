/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

//BFS Solution, DFS would be neater

#include <queue>
#include <math.h>
typedef pair<int,int> pr;

class Solution {
public:
    bool isSafe (int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid) 
    { 
        return (i >= 0) && (i < grid.size()) &&  
               (j >= 0) && (j < grid[i].size()) &&  
               (!visited[i][j]); 
    } 
    
    void BFS(pr idx,vector<vector<bool>> &visited,vector<vector<char>> &grid){
        
        queue<pr> land_set;
        land_set.push(idx);
        visited[idx.first][idx.second] = true;
        
        vector<int> row = { -1, 0, 0, 1 }; 
        vector<int> col = {  0, 1, -1, 0}; 
        
        while(!land_set.empty()){
            pr ind_pair= land_set.front();
            land_set.pop();
            int i = ind_pair.first;
            int j = ind_pair.second;
            for (int k = 0; k < row.size(); k++) { 
                if (isSafe(i + row[k], j + col[k], visited, grid)) { 
                    visited[i + row[k]][j + col[k]] = true; 
                    if(grid[i + row[k]][j + col[k]]=='1')
                        land_set.push(make_pair(i + row[k], j + col[k])); 
                } 
            } 
        }
        //return isLand;
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int ct = 0;
        queue <pr> land;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        
        for(int i =0;i<grid.size();++i){
            for(int j=0; j<grid[i].size();++j){
                //cout<<grid[i][j]<<" ";
                if(grid[i][j]=='1'&&!visited[i][j]){
                    BFS(make_pair(i,j),visited,grid);
                    ct++;
                }
            }
            //cout<<endl;
        }
        return ct;
    }
};
