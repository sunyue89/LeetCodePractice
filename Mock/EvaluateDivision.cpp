/*Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
 

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

Last Submission
Last Saved Code*/

class Solution {
public:
    bool DFS(vector<vector<pair<int,double>>>& g, int a, int b, vector<bool>& vis, double m, double& v){
        //cout<<a<<" "<<b<<endl;
        if(a==b){
            v = m;
            return true;
        }
        if(!vis[a]){
            vis[a] = true;
            for(const auto x:g[a]){
                int n = x.first;
                double t = m*x.second;
                //cout<<n<<" "<<m<<" "<<v<<endl;
                if(DFS(g,n,b,vis,t,v))
                    return true;
            }
        }
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        unordered_map<string,int> sm;//string to node
        vector<vector<pair<int,double>>> g; //graph with format n -> (n,v)
        int j = 0;
        for(int i=0; i<values.size(); ++i){
            string a = equations[i][0];
            string b = equations[i][1];
            double v = values[i];
            if(sm.find(a)==sm.end()){
                sm[a] = j;
                g.resize(j+1);
                j++;
            }
            if(sm.find(b)==sm.end()){
                sm[b] = j;
                g.resize(j+1);
                j++;
            }
            g[sm[a]].push_back({sm[b],v});
            g[sm[b]].push_back({sm[a],1/v});
        }
        vector<double> o;
        for(const auto q:queries){
            if( sm.find(q[0]) == sm.end() ){
                o.push_back(-1.0);
                continue;
            }
            if( sm.find(q[1]) == sm.end() ){
                o.push_back(-1.0);
                continue;
            }
            int a = sm[q[0]];
            int b = sm[q[1]];
            double v = 1.0;
            vector<bool> vis(j,false);
            if(DFS(g,a,b,vis,1.0,v))
                o.push_back(v);
            else
                o.push_back(-1.0);
            cout<<endl;
        }
        return o;
    }
};
