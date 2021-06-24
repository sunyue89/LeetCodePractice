/*All Paths From Source to Target

Solution
Given a directed acyclic graph of N nodes. Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 

Constraints:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.*/

class Solution {
public:
    void DFS(vector<vector<int>>& graph, int s, int t, vector<bool>& vis, vector<int>& p, vector<vector<int>>& out){

        if(vis[s])
            return;
        vis[s] = true;
        p.push_back(s);
        if(s==t){
            out.push_back(p);
            //return;
        }
        for(auto g:graph[s]){
            DFS(graph,g,t,vis,p,out);
        }
        vis[s] = false;
        p.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> out;
        vector<int> p;
        vector<bool> vis(graph.size(),false);
        DFS(graph,0,graph.size()-1,vis,p,out);
        return out;
    }
};
