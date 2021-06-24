/*On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:

Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
Note:

2 <= N <= 50.
grid[i][j] is a permutation of [0, ..., N*N - 1].*/

typedef pair<int, pair<int,int>> pq;

class Solution {
    vector<vector<int>> nbr = {{-1,0},{1,0},{0,-1},{0,1}};
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pq, vector<pq>, greater<pq>> que;
        vector<vector<bool>> vis(m,vector<bool>(n));
        que.push({grid[0][0],{0,0}});
        vis[0][0] = true;
        int tmin = 0;
        while(!que.empty()){
            pq tp = que.top();
            que.pop();
            tmin = max(tmin,tp.first);
            int i = tp.second.first;
            int j = tp.second.second;
            //cout<<i<<" "<<j<<" "<<tp.first<<endl;
            vis[i][j] = true;
            if(i==m-1 && j==n-1)
                break;
            for(auto& v:nbr){
                int p = i+v[0];
                int q = j+v[1];
                if(p>=0 && p<m && q>=0 && q<n && !vis[p][q])
                    que.push({grid[p][q],{p,q}});
            }
        }
        return tmin;
    }
};
