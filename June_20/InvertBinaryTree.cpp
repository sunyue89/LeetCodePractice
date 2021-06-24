/*
nvert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
    void DFS(TreeNode* root){
        if(root==nullptr)
            return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        DFS(root->left);
        DFS(root->right);
            
    }
    TreeNode* invertTree(TreeNode* root) {
        DFS(root);
        return root;
    }
};
