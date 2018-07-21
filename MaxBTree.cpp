/*
 Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

    The root is the maximum number in the array.
    The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Example 1:

Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

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
    TreeNode* constructMaximumBinaryTree(vector<int>& vecnum)
    {
        return ConstructMaximBTreeUtil(vecnum, 0, vecnum.size()-1);
        
    }
    TreeNode* ConstructMaximBTreeUtil(vector<int> vecnum, int low, int high)
    {   
      if(low > high)
       return NULL;

      int index =0;
      int maxnum = FindMaxNuminArray(vecnum, low, high, index) ;
   
      TreeNode* node  = (TreeNode*) malloc(sizeof(struct TreeNode));
      node->val =maxnum;
      node->left  = ConstructMaximBTreeUtil(vecnum, low, index-1);
      node->right = ConstructMaximBTreeUtil(vecnum, index+1, high);

   return node;
}
 int FindMaxNuminArray(vector<int> vecnum, int low, int high, int& index) 
{
  int maxnum = vecnum[low];
  int count =low;
  index = low;
  while(count <= high)
  {
    if(vecnum[count] > maxnum)
    {
      maxnum = vecnum[count];
      index = count;
    }
    count++;
  }
  return maxnum;
}
};