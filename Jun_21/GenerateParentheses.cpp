/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    bool checkVal(string& S){
        int inc = 0;
        for(auto c:S){
            int dlt = c=='(' ? 1:-1;
            inc += dlt;
            if(inc<0)
                return false;
        }
        return inc == 0 ? true:false;
    }
    
    void solve(string S, int N, vector<string>& rlt){
        //cout<<S<<endl;
        if(S.size() == N){
            if(checkVal(S))
                rlt.push_back(S);
            return;
        }
        solve(S+'(',N,rlt);
        solve(S+')',N,rlt);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> rlt;
        solve("",2*n,rlt);
        return rlt;
    }
};
