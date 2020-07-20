/*Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
Last Submission
Last Saved Code

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
    void DFS(TreeNode* root, bool l, int& val){
        if(root==nullptr)
            return;
        if(l && root->left==nullptr && root->right==nullptr)
            val+=root->val;
        DFS(root->left,true,val);
        DFS(root->right,false,val);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int val=0;
        DFS(root,false,val);
        return val;
    }
};
