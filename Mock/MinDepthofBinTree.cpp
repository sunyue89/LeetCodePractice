/*Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

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
    int minH(TreeNode* root,int h){
        if(root==nullptr)
            return INF_MAX;
        if(root->left==nullptr && root->right==nullptr)
            return h;
        return min(minH(root->left,h+1),minH(root->right,h+1));
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        return minH(root,1);
    }
private:
    const int INF_MAX = 10000000000;
};
