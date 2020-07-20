/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/

class Solution {
public:
    void DFS(unordered_map<string,vector<string>>& bk,string n,unordered_map<string,vector<bool>>& vis, vector<string>& rlt){
        
        if(bk.find(n)!=bk.end()){
            for(int i=0; i<bk[n].size(); ++i){
                if(!vis[n][i]){
                    vis[n][i] = true;
                    //if(DFS(bk,bk[n][i],vis,rlt))
                        //return true;
                    DFS(bk,bk[n][i],vis,rlt);
                }
            }
        }
        rlt.insert(rlt.begin(),n);
        //cout<<n<<" "<<endl;
        //return false;
        return;
    }
        
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string,vector<string>> bk;
        unordered_map<string,vector<bool>> vis;
        
        for(const auto& a:tickets){
            string tmp = "";
            for(int i=0;i<a.size();++i){
                if(0==i){
                    tmp = a[i];
                }
                else{
                    bk[tmp].push_back(a[i]);
                    vis[tmp].push_back(false);
                }
            }
        }
        
        for(auto i=bk.begin();i!=bk.end();++i){
            sort(i->second.begin(),i->second.end());
        }
        
        vector<string> rlt;
        DFS(bk,"JFK",vis,rlt);
        return rlt;
    }
};
