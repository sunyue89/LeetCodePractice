/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

class Trie {
public:
    /** Initialize your data structure here. */
    struct Node{
        char ele;
        bool end;
        vector<Node*> next;
        Node(): end(false),next(vector<Node*>(0,NULL)){}
        Node(char a): ele(a),end(false),next(vector<Node*>(0,NULL)){}
    };
    
    Node* rt;
    
    Trie() {
        rt = new Node();
    }
    
    ~Trie() {
        delete rt;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* root=rt;
        Node* n;
        for(int i=0;i<word.length();++i){
            int j;
            for(j=0; j<root->next.size(); ++j){
                if(root->next[j]->ele==word[i]){
                    n = root->next[j];
                    break;
                }
            }
            if(j>=root->next.size()){
                 n = new Node(word[i]);
                 root->next.push_back(n);
            }
            root = n;
        }
        root->end = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* root=rt;
        for(int i=0;i<word.length();++i){
            int j;
            for(j=0;j<root->next.size();++j){
                if(root->next[j]->ele==word[i]){
                    break;
                }
            }
            if (j>=root->next.size())
                return false;
            root = root->next[j];
        }
        return root->end;
            
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* root=rt;
        for(int i=0;i<prefix.length();++i){
            int j;
            for(j=0;j< root->next.size();++j){
                if(root->next[j]->ele==prefix[i]){
                    break;
                }
            }
            if (j>=root->next.size())
                return false;
            root = root->next[j];
        }
        return true;
    }
};

class Solution {
public:
    //run DFS and compare prefix with the constucted trie
    bool CheckValid(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& vis){
        return (i>=0 && i<board.size() && j>=0 && j<board[0].size());
    }
    void DFS(vector<vector<char>>& board, int i, int j, string& w, vector<string>& s, Trie* t, unordered_set<string>& wds, vector<vector<bool>>& vis){
        //cout<<w<<" "<<vis[i][j]<<endl;
        if(vis[i][j])
            return;
        vis[i][j]=true;
        if(wds.find(w) == wds.end()){
            if(t->search(w)){
                s.push_back(w);
                wds.insert(w);
            }
        }
        vector<pair<int,int>> idx ={{-1,0},{1,0},{0,1},{0,-1}};
        for(const auto& pr:idx){
            int it = i+pr.first;
            int jt = j+pr.second;
            if(CheckValid(board,it,jt,vis)){
                string tmp = w + board[it][jt];
                if(t->startsWith(tmp))
                    DFS(board,it,jt,tmp,s,t,wds,vis);
            }
        }
        vis[i][j]=false;
        return; 
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //initiate the trie
        Trie* T_board = new Trie();
        unordered_set<string> wds;
        //convert the word to trie
        for(const auto& w:words){
            T_board->insert(w);
        }
        //search each word and check exsitence in the board
        vector<string> out;
        
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                string s;
                s = board[i][j];
                vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
                //cout<<s<<endl;
                DFS(board,i,j,s,out,T_board,wds,vis);
            }
        }
        //destruct automatically due to function stack call
        return out;
    }
};


