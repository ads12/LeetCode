/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,
*/

#include <unordered_map>
using namespace std;

class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target)
    {
       unordered_map<int, int> Mapnum;
       vector <int> result;
       for(int count =0 ; count <nums.size(); count++)
       {
         Mapnum[nums.at(count)] =  count;     
       }
       //map<int, int>::iterator iter = Mapnum.begin();

      for(int count =0 ; count <nums.size(); count++)
      {
        if(Mapnum.find(nums.at(count)) !=Mapnum.end())
        {   
          unordered_map<int, int>::iterator iter = Mapnum.find(target -nums.at(count));
          if(iter!=Mapnum.end() && iter->second != count)
          {
            result.push_back(count);
            result.push_back(iter->second);
            return result;
          }
       }
     }
     return result;
    }
};