/*
Implement Trie (Prefix Tree)

Solution
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
