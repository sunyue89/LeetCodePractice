/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

//MST Problem

typedef pair<pair<int,int>,int> pr;
const int INF = 1000000;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        vector<vector<int>> cost(grid.size(),vector<int>(grid[0].size(),INF));
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        pq.push(make_pair(make_pair(0,0),(cost[0][0]=grid[0][0])));
        while(!pq.empty()){
            pr ele = pq.top();
            int i = ele.first.first;
            int j = ele.first.second;
            int sum = ele.second;
            pq.pop();  
            if(i+1<grid.size()&&sum+grid[i+1][j]<cost[i+1][j]){
                cost[i+1][j] = sum+grid[i+1][j];
                pq.push(make_pair(make_pair(i+1,j),cost[i+1][j]));
            }
            if(j+1<grid[i].size()&&sum+grid[i][j+1]<cost[i][j+1]){
                cost[i][j+1] = sum+grid[i][j+1];
                pq.push(make_pair(make_pair(i,j+1),cost[i][j+1]));
            }
        }
        return cost[grid.size()-1][grid[0].size()-1];
    }
};
