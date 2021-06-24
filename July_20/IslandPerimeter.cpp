/*
Island Perimeter

Solution
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:


*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p=0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j])
                    DFS(grid,i,j,vis,p);
        return p;
    }
private:
    vector<vector<int>> Sur = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool isValidI(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
        return (i>=0 && i<=grid.size()-1 && j>=0 && j<=grid[0].size()-1 && !vis[i][j] && grid[i][j]);
    }
    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis, int& p){
        if(!vis[i][j]){
            vis[i][j] = true;
            p+=calP(grid,i,j);
            //cout<<i<<" "<<j<<" "<<p<<endl;
            for(const auto& s:Sur)
                if(isValidI(grid,i+s[0],j+s[1],vis))
                    DFS(grid,i+s[0],j+s[1],vis,p);
        }
        return;
    }
    bool isValidW(vector<vector<int>>& grid, int i, int j){
        //cout<<i<<" "<<j<<endl;
        if(i<0)
            return true;
        if(i>grid.size()-1)
            return true;
        if(j<0)
            return true;
        if(j>grid[0].size()-1)
            return true;
        //cout<<grid[i][j]<<endl;
        return (i>=0 && i<=grid.size()-1 && j>=0 && j<=grid[0].size()-1 && !grid[i][j]);
    }
    int calP(vector<vector<int>>& grid, int i, int j){
        int p=0;
        for(const auto& s:Sur){
            if(isValidW(grid,i+s[0],j+s[1])){
                p+=1;
            }
        }
        return p;
    }
};
