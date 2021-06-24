/*
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.
*/

typedef pair<int,int> pr;

class Solution {
public:
    vector<vector<pr>> make_graph(int n, vector<vector<int>>& flights){
        vector<vector<pr>> graph(n);
        for(const auto& x:flights){
            graph[x[0]].push_back(make_pair(x[1],x[2]));
            //cout<<x[0]<<" "<<graph[x[0]][graph[x[0]].size()-1].first<<" "<<graph[x[0]][graph[x[0]].size()-1].second<<endl;
        }
        return graph;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        priority_queue<Ele, vector<Ele>, CompareEle> pq;
        vector<vector<pr>> graph = make_graph(n,flights);
        //vector<int> par(n,-1);
        
        pq.push(Ele(0,-1,src));
        int ct = 0;

        while(!pq.empty()){
            Ele x = pq.top();
            pq.pop();
            int node = x.n;
            int c = x.cost;
            int t = x.cts;
            
            //cout<<node<<" "<<c<<" "<<t<<endl;
            
            if(node==dst && t<=K)
                return c;
            
            if(ct>n*(n-1))
                break;
                
            for(const auto& y:graph[node]){
                pq.push(Ele(c+y.second,t+1,y.first));
            }
            ct++;
        }
        return -1;
    }
private:
    struct Ele{
        int cost;
        int cts;
        int n;
        Ele(int x, int y, int z): cost(x),cts(y),n(z){}
    };
    
    struct CompareEle { 
        bool operator()(const Ele& e1, const Ele& e2) 
        { 
            return (e1.cost > e2.cost) || (e1.cost==e2.cost && e1.cts>e2.cts); 
        } 
    }; 
};
