/*
Course Schedule II

Solution
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

class Solution {
public:
    #if 0
    bool DFS_Cycle(vector<vector<int>>& g, int n, vector<int>& vis, vector<int>& o){
        if(vis[n]==1)
            return true;
        if(vis[n]==2)
            return false;
        vis[n] = 1;
        for(const auto& x:g[n]){
            if(DFS_Cycle(g,x,vis,o))
                return true;
        }
        vis[n] = 2;
        o.push_back(n);
        return false; 
    }
    #endif
    
    bool DFS_Cycle(vector<vector<int>>& g, int n, vector<bool>& vis, vector<bool>& pre, vector<int>& o){
        if(!vis[n]){
            vis[n]=true;
            pre[n]=true;
            for(const auto& x:g[n]){
                if(pre[x] || DFS_Cycle(g,x,vis,pre,o))
                    return true;
            }
            o.push_back(n);
        }
        pre[n]=false;
        return false; 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(const auto& p:prerequisites){
            g[p[0]].push_back(p[1]);
        }
        #if 0
        vector<int> vis(numCourses,0);
        #endif
        vector<bool> vis(numCourses,false);
        vector<bool> pre(numCourses,false);
        vector<int> out;
        for(int i=0; i<numCourses; ++i){
            if (DFS_Cycle(g,i,vis,pre,out)) {
                return {};
            }
        }
        return out;
    }
};
