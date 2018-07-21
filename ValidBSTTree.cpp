/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

Input:
    2
   / \
  1   3
Output: true

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
    
bool isValidBST(struct TreeNode* root)
{
  return isValidBSTUtil(root, LONG_MIN, LONG_MAX);    
}
bool isValidBSTUtil(struct TreeNode* root, long int min, long int max)
{
  if(root == NULL)
    return true;
  if(root->val > min && root->val < max) 
   return  isValidBSTUtil( root->left, min, root->val) &&
           isValidBSTUtil( root->right, root->val, max);
  
  return false;
}
};