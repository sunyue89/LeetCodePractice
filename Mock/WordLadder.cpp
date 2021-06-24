/*Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
Last Submission
Last Saved Code*/

class Solution {
public:
    bool change(string b,string e,int n, int init){
        if(b.length()!=e.length())
            return false;
        int ct = 0;
        int t = 2;
        if(n==-1 && init == -1) // reverse search
            t = 1;
        for(int i=0;i<b.length();++i){
            if(b[i]!=e[i])
                ct++;
            if(ct>=t)
                return false;
        }
        return true;
    }
    void BFS(string b, vector<string>& w, vector<bool>& v, queue<int>& q, vector<int>& d, int init){
        int i = q.front();
        q.pop();
        if(i!=-1){
            b = w[i];
        }
        for(int j=0;j<w.size();++j){
            if(!v[j] && change(b,w[j],i,init)){
                int t = (i==-1? init:d[i]);
                d[j] = t + 1;
                q.push(j);
                v[j] = true;
            }
        }
        return;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> vb(wordList.size(),false),ve(wordList.size(),false);
        vector<int> db(wordList.size(),1),de(wordList.size(),0);
        queue<int> qb,qe;
        qb.push(-1);
        qe.push(-1);
        while(!qb.empty() && !qe.empty()){
            BFS(beginWord,wordList,vb,qb,db,1);
            BFS(endWord,wordList,ve,qe,de,-1);
            for(int i=0;i<vb.size();++i){
                if (vb[i]&&ve[i])
                    return db[i]+de[i];
            }
        }
        return 0;
    }
};
