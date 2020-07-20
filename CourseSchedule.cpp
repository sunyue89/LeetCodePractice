/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

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
Last Submission
Last Saved Code*/


class Solution {
public:
    /*
    vector<vector<int>> makeGraph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> g(numCourses);
        for(const auto& p:prerequisites){
            g[p[0]].push_back(p[1]);
        }
        return g;
    }*/
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        graph_ = vector<vector<int>>(numCourses);
        
        for(const auto& p : prerequisites)
            graph_[p[0]].push_back(p[1]);
        
        // states: 0 = unkonwn, 1 == visiting, 2 = visited
        vector<int> v(numCourses, 0);
        
        for(int i = 0; i < numCourses; ++i)
            if(dfs(i, v)) return false;
        
        return true;
    }
    
private:
    vector<vector<int>> graph_;
    bool dfs(int cur, vector<int>& v) {
        if(v[cur] == 1) return true;
        if(v[cur] == 2) return false;
        
        v[cur] = 1;
        
        for(const int t : graph_[cur])
            if(dfs(t, v)) return true;
        
        v[cur] = 2;
        
        return false;
    }
};
