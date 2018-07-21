/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

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
    
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
       vector<vector<int>> VecofVecofInt;  
       vector<int> VecInt;
       int height= FindBSTHeight(root);
        
        for(int i=1; i <= height; i++)
        {
           FindNodeatGivenLevel(root, i,  VecInt);
          if(i%2 ==0)
              reverse(VecInt.begin(), VecInt.end());
           VecofVecofInt.push_back(VecInt);
           VecInt.clear();
        }
        return VecofVecofInt;        
    }
    
    int FindBSTHeight(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int lheight = FindBSTHeight(root->left);
        int rheight = FindBSTHeight(root->right);
        
        return lheight > rheight? lheight+1: rheight+1;
    }
    
    void FindNodeatGivenLevel(TreeNode *root, int level, vector<int>& VecInt)
    {      
      if(root == NULL)   
          return;
     if(level == 1)
     {
       return VecInt.push_back(root->val);   
     }
     FindNodeatGivenLevel(root->left, level-1,VecInt);
     FindNodeatGivenLevel(root->right, level-1,VecInt);   
   
    }
};