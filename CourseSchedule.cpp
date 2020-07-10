/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/

class Solution {
public:
    vector<vector<int>> makeGraph(int numCourses,vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses); 
        for(int i=0; i<prerequisites.size(); ++i){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return graph;
    }
    bool DFS_Cycle(int n, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& par){
        if(vis[n]==false){
            vis[n] = true;
            par[n] = true;
            for(int i=0; i<graph[n].size(); ++i){
                //cout<<n<< graph[n][i]<< vis[graph[n][i]]<< par[graph[n][i]]<<endl;
                if(!vis[graph[n][i]] && DFS_Cycle(graph[n][i],graph,vis,par)){
                    return true;
                }else{
                    if(par[graph[n][i]])
                        return true;
                }
            }
        }
        par[n] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = makeGraph(numCourses,prerequisites);
        vector<bool> par(numCourses,false);
        vector<bool> vis(numCourses,false);
        
        for(int i=0;i<numCourses;++i){
            if(DFS_Cycle(i,graph,vis,par))
                return false;
        }
        return true;
    }
};
