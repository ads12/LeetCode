/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

Example 1:

Input: root = [2,1,3], p = 1

  2
 / \
1   3

Output: 2
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
class Solution {
public:
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
{
   if(p->right)
  {
    struct TreeNode* curr = p->right;
    while(curr->left)
    {
      curr = curr->left;
    }   
    return curr;
  }
  struct TreeNode* suc = NULL;

  while(root != NULL)
  {
    if(root->val > p->val) 
    {
      suc = root;
      root = root->left;
    }
    else if(root ->val < p->val)
      root = root->right;
    else if(root->val == p->val)
      return suc;
  }
  return suc;        
}
};