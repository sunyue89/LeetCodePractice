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

//[8,5,1,7,10,12]
//i = 0; key = 8, min = MIN, max = MAX
//  return node with key 8
//  node->left = (1,5,min,8)
//  i = 1; key = 5, min = MIN, max = 8
//    return node->left with key 5
//    node->left = (2,1,min,5)
//      i = 2; key = 1, min = MIN, max = 5
//          return node->left with key 1
//          node -> left = (3,7,min,1)
//              i=3; key=7; min = MIN, max = 1
//              return node->left with NULL, pop to prev node
//  node -> right = (3,7,1,max)
//      i = 3, key = 7, min = 1, max = MAX
//      return node->right with key 7
//                
//i = 4, key = 10, min =7 , max = MAX
//    node->right = (4,10,7,max)
//    i=5, key = 12, min = 10, max = MAX
//    node->right = (5,12,10,max) 



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
