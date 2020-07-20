/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
Last Submission
Last Saved Code
**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 *
*/
class Solution {
public:
    
    int findMaxUtil(TreeNode* root, int &res) 
    { 
        //Base Case 
        if (root == NULL) 
            return 0; 

        // l and r store maximum path sum going through left and 
        // right child of root respectively 
        int l = findMaxUtil(root->left,res); 
        int r = findMaxUtil(root->right,res); 

        // Max path for parent call of root. This path must 
        // include at-most one child of root 
        int max_single = max(max(l, r) + root->val, root->val); 

        // Max Top represents the sum when the Node under 
        // consideration is the root of the maxsum path and no 
        // ancestors of root are there in max sum path 
        int max_top = max(max_single, l + r + root->val); 

        res = max(res, max_top); // Store the Maximum Result. 

        return max_single; 
    } 

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int t = findMaxUtil(root,res);
        return res;
    }
};
