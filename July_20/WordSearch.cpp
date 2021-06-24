/*
Word Search

Solution
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

class Solution {
public:
    bool CheckValid(vector<vector<char>>& board, int i, int j){
        return (i>=0 && i<=board.size()-1 && j>=0 && j<=board[0].size()-1);
    }
    bool DFS(vector<vector<char>>& board, int i, int j, int k, int l, string word, vector<vector<bool>>& vis){
        if(vis[i][j])
            return false;
        
        vis[i][j] = true;
        if(board[i][j]==word[k]){
            if(k+1>=l)
                return true;
            for(auto x:n){
                if(CheckValid(board,i+x[0],j+x[1]) && DFS(board,i+x[0],j+x[1],k+1,l,word,vis))
                    return true;
            }
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int l = word.length();
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(DFS(board,i,j,0,l,word,vis))
                    return true;
            }
        }
        return false;
    }
private:
    vector<vector<int>> n = {{-1,0},{1,0},{0,-1},{0,1}};
};
