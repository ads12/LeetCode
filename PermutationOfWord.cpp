/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
      vector<vector<int>> vecOfVecInt;
      GeneratepermutationUtil(nums, 0, vecOfVecInt);
      return vecOfVecInt;        
    }
    void GeneratepermutationUtil(vector<int>& nums, int pos, vector<vector<int>>& vecOfVecInt)
    {      
      if(pos == nums.size()-1)
      {        
        vecOfVecInt.push_back(nums);
        return;
      }
      for(int count=pos; count < nums.size(); count++)
      {
        swap(nums.at(count), nums.at (pos));
        GeneratepermutationUtil(nums, pos+1, vecOfVecInt);    
        swap(nums.at(pos),nums.at(count));
      }
   }
};