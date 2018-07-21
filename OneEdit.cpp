/*
Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

    Insert a character into s to get t
    Delete a character from s to get t
    Replace a character of s to get t

Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

*/
class Solution {
public:
bool isOneEditDistance(string s, string t)
{
  if(s.compare(t) == 0)
      return false;
  int len1 = s.length();       
  int len2 = t.length();
  int count = 0;
  int i =0;
  if(len1 == len2)
  {
    while(i < len1)
    {
      if(s[i] !=t[i])
        count++;
      i++;
    }
  }
  else if(len1 < len2)
  {
    while(s[i] ==t[i])
      i++;
      
    if(s[i] != t[i])
    {      
      t.erase(i,1);
      count++;
      if(s.compare(t) != 0)
        count++;
    }
  }
  else if(len1 > len2)
  {
    //s.swap(t);
    return isOneEditDistance(t, s);
    /*while(s[i] ==t[i])
      i++;
      
    if(s[i] != t[i])
    {      
      t.insert(i,1,s[i]);
      count++;
      if(s.compare(t) != 0)
        count++;
    }*/
  }
  return count <=1;        
}
};