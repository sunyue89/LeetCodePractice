/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//preorder traversal
//void trav(TreeNode *node);
//if(node == NULL) return;
//preorder.push_back(node->value);
//trav(node->left);
//trav(node->right);

//create the bst
//print level traversal

//use recursion to recover
const int INF_min = -100000000;
const int INF_max = 100000000;
class Solution {
public:

    TreeNode* bstRoot(vector<int>& preorder, int &i, int key, int min, int max){
        if(i>=preorder.size()) return NULL;
        TreeNode* node = NULL;
        
        if(key>min && key<max){
            
            node = new TreeNode();
            node->val = key;
            i++;
            if(i<preorder.size())   
                node->left = bstRoot(preorder,i,preorder[i], min, key);
            if(i<preorder.size()) 
                node->right = bstRoot(preorder,i,preorder[i],key, max);
        }
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.size()==0) return NULL;
        int i = 0;
        //TreeNode* root = new TreeNode();
        //root->val = preorder[i];
        TreeNode* root = bstRoot(preorder,i,preorder[i],INF_min,INF_max);
        return root;
    }
};
