/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
*/

//5
//[[1,2],[3,4],[4,5],[3,5]]

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        if(dislikes.size()==0) 
            return true;
        
        vector<vector<int>> graph(N);
        
        for(int i=0;i<dislikes.size();++i){
      
            graph[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            graph[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
           
        }
        vector<int> visited(N,0);
        queue <int> node;
        
        for(int i=0;i<N;++i){
            if(visited[i]==0){
                node.push(i);
                visited[i]=1;
                while(!node.empty()){
                    int n = node.front();
                    //cout<<i+1<<" "<<n+1<<endl;
                    node.pop();
                    for(int j=0;j<graph[n].size();++j){
                        //cout<<graph[n][j]+1<<endl;
                        if(visited[graph[n][j]]==visited[n])
                            return false;
                        if(visited[graph[n][j]]==0){
                            visited[graph[n][j]] = -visited[n];
                            node.push(graph[n][j]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
