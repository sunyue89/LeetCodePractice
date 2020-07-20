/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution {
public:
    bool CheckValid(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis){
        return (i>0 && i<board.size()-1 && j>0 && j<board[0].size()-1 && vis[i][j] == false && board[i][j] == 'O');
    }
    bool OnEdgeO(int i, int j, vector<vector<char>>& board){
        return (i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1) && board[i][j] == 'O';
    }
    void DFS(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis, bool& edge, vector<vector<int>>& idx){
        vis[i][j] = true;
        //cout<<i<<j<<endl;
        vector<vector<int>> sur = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto& x:sur){
            if(CheckValid(i+x[0],j+x[1],board,vis)){
                DFS(i+x[0],j+x[1],board,vis,edge,idx);
            }else if(OnEdgeO(i+x[0],j+x[1],board)){
                edge = true;
                //cout<<i<<j<<edge<<endl;
            }
        }
        idx.push_back({i,j});
        return;
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return;
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        vector<vector<bool>> onedge(board.size(),vector<bool>(board[0].size(),false));
        
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(CheckValid(i,j,board,vis)){
                    bool edge = false;
                    vector<vector<int>> idx;
                    DFS(i,j,board,vis,edge,idx);
                    if(!edge){
                        for(auto x:idx)
                            board[x[0]][x[1]] = 'X';
                    }
                }
            }
        }
        return;
    }
};
