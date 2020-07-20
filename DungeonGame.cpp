/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
 

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        if(dungeon.size()==0)
            return 1;
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> score(m,vector<int>(n,0));
        
        score[m-1][n-1] = max(1,-dungeon[m-1][n-1]+1);
        
        for(int i=m-2;i>=0;i--){
            score[i][n-1] = max(1,score[i+1][n-1]-dungeon[i][n-1]);
        }
        
        for(int j=n-2;j>=0;j--){
            score[m-1][j] = max(1,score[m-1][j+1]-dungeon[m-1][j]);
        }
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                score[i][j] = max(min(score[i+1][j],score[i][j+1])-dungeon[i][j],1);
            }
        }
        
        return score[0][0];
        
        //greedy algo does not apply well to negative cycle graphs (and with complex bounding conditions)
        #if 0
        typedef pair<int,int> pr;
        typedef pair<int,pr> prq;
        if(dungeon.size()==0)
            return 1;
        priority_queue <prq> pq;
        vector<vector<int>> score(dungeon.size(),vector<int>(dungeon[0].size(),INT_MIN));
        vector<vector<pr>> par(dungeon.size(),vector<pr>(dungeon[0].size(),{-1,-1}));
        int i = 0;
        int j = 0;
        prq n = make_pair(dungeon[i][j],make_pair(i,j));
        int K = -n.first+1;
        pq.push(n);
        while(!pq.empty()){
            prq n = pq.top();
            pq.pop();
            int cost = n.first;
            pr idx = n.second;
            //vis[idx.first][idx.second] = true;
            K = max(K,-cost+1);
            cout<<idx.first<<" "<<idx.second<<" "<<cost<<" "<<K<<endl;
            if(idx.first==dungeon.size()-1&&idx.second==dungeon[0].size()-1)
                return max(K,1);
            if(idx.first+1<dungeon.size()){
                int tc = cost+dungeon[idx.first+1][idx.second];
                if(tc>=score[idx.first+1][idx.second]){
                    pq.push(make_pair(tc,make_pair(idx.first+1,idx.second)));
                }
            }
            if(idx.second+1<dungeon[0].size()){
                //par[idx.first][idx.second+1] = idx;
                int tc = cost+dungeon[idx.first][idx.second+1];
                if(tc>=score[idx.first][idx.second+1]){
                    pq.push(make_pair(tc,make_pair(idx.first,idx.second+1)));
                }
            }   
        }
        return max(K,1);
        #endif
    }
};
