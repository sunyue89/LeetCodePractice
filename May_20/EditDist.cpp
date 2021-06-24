/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

//  r o s
//h
//o
//r
//s
//e

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dis(word1.length()+1,vector<int>(word2.length()+1,0));
        
        for(int i=0;i<dis.size();++i)
            dis[i][0] = i;
        for(int j=0;j<dis[0].size();++j)
            dis[0][j] = j;
        
        for(int i=1;i<dis.size();++i){
            for(int j=1;j<dis[i].size();++j){
                if(word1[i-1]==word2[j-1]){
                    dis[i][j] = dis[i-1][j-1];
                }else{
                    dis[i][j] = 1+min(dis[i-1][j-1],min(dis[i-1][j],dis[i][j-1]));
                }
            }
        }
        return (dis[dis.size()-1][dis[0].size()-1]);
    }
};
