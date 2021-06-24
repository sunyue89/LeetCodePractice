/*
Binary Tree Zigzag Level Order Traversal

Solution
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//         r       n 
//n    rl     rr  
//  rll rlr rrl rrr n

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool z = true;
        queue<TreeNode*> q;
        vector<vector<int>> o;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            int s = q.size();
            vector<int> v;
            while(s--){
                TreeNode* t= q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(!z)
                reverse(v.begin(),v.end());
            o.push_back(v);
            z = !z;
        }
        return o;
    }
};
