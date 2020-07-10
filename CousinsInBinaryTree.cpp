/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
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
    bool isCousins(TreeNode* root, int x, int y) {
        int x_root=0, y_root=0;
        int xh = DFS(root,x_root,x,0);
        int yh = DFS(root,y_root,y,0);
        //cout<<x_root<<" "<<xh<<endl;
        //cout<<y_root<<" "<<yh<<endl;
        return (xh==yh && x_root != y_root);
    }
    int DFS(TreeNode* root, int& x_root, int x, int h){
        if(root==NULL) return 0;
        if(root->left != NULL && root->left->val == x){
            x_root = root->val;
            return h+1;
        } 
        if(root->right != NULL && root->right->val == x){
            x_root = root->val;
            return h+1;
        }
        int l = DFS(root->left,x_root,x,h+1);
        if(l!=0) return l;
        int r = DFS(root->right,x_root,x,h+1);
        return r;
    }
};
