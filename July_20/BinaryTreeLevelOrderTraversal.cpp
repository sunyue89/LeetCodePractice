/*
Binary Tree Level Order Traversal II

Solution
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> out;
        queue<TreeNode*> q;
        //stack<TreeNode*> s;
        int level = 0;
        
        if(root!=nullptr){
            q.push(root);
            q.push(nullptr);
        }
        
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();

            //s.push(tmp);
            if(tmp==nullptr){
                if(!q.empty() && q.front()!=nullptr){
                    q.push(nullptr);
                    level+=1;
                }
            }else{
                if(out.size()!=level+1){
                    out.insert(out.begin(),{tmp->val});
                }else{
                    out[0].push_back(tmp->val);
                }
                if(tmp->left != nullptr){
                    q.push(tmp->left);
                }
                if(tmp->right != nullptr){
                    q.push(tmp->right);
                } 

            }
        }
        
        return out;
    }
};
