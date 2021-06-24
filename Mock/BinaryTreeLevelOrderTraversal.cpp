/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
Last Submission
Last Saved Code*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        queue<TreeNode*> q;
        int lv=1;
        if(root!=nullptr){
            q.push(root);
            q.push(nullptr);
        }
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            
            if(out.size()!=lv)
                out.resize(lv);
            
            if(tmp==nullptr){
                if(!q.empty()&&q.front()!=nullptr){
                    lv++;
                    q.push(nullptr);
                }
            }else{
                out[lv-1].push_back(tmp->val);
                if(tmp->left != nullptr)
                    q.push(tmp->left);
                if(tmp->right != nullptr)
                    q.push(tmp->right);
            }
        }
        return out;
    }
};
