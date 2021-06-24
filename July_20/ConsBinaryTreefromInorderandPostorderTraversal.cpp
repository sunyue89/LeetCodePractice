/*
Construct Binary Tree from Inorder and Postorder Traversal

Solution
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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

//in-order      l->o->r
//post-order    l->r->o
class Solution {
public:
    
    TreeNode* helper(unordered_map<int,int>& mp, vector<int>& inorder, vector<int>& postorder, int i_first, int i_last)
    {
        if(i_first > i_last) // base condition by checking size of subtree
            return NULL;
        
        // the approach I have used is to first find the root node value, then break the inorder vector into left subtree and right subtree with respect to the root node. Then filling its left and right subtrees and finally returning the root node.
        int val,index = -1;
        // the node which lies inside the range of given inorder and is rightmost in the postorder is regarded as the current root node.
        for(auto it=postorder.rbegin();it!=postorder.rend();it++)
        {
            if(mp[*it] >= i_first && mp[*it] <= i_last)
            {
                index = mp[*it];
                break;
            }
        }
        val = inorder[index];
        TreeNode* root = new TreeNode(val);
        
        root->left = helper(mp,inorder,postorder,i_first,index-1);
        root->right = helper(mp,inorder,postorder,index+1,i_last);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();++i)
            mp[inorder[i]] = i;
        return helper(mp,inorder,postorder,0,postorder.size()-1);
    }
};
