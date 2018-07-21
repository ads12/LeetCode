/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
*/

class Solution {
public:

    int compareVersion(string version1, string version2)
{
  int result = 0;
  int start1=0,start2 =0;
  while(start1 < version1.size() || start2 < version2.size())
  {
     int len1 =0, len2 =0;
     int num1 =  ConvertVersionToInt(version1, start1, len1);
     int num2 =  ConvertVersionToInt(version2, start2,len2);
     if(num1 < num2 && result !=1)       
     {
       result = -1;
       break;
     }
     else if(!(num1 == num2))
       result =1;
  }
  return result;
}

int ConvertVersionToInt(string version, int& start, int& len)
{
  int num =0;
  int pos = version.find(".", start);
  if(pos != string::npos)
  {
    string substr = version.substr(start, pos-start);
    len = substr.length();
    num = strtol(substr.c_str(),NULL,10);
    start = pos+1;
  }
  else if(start < version.size())
  {
    string substr = version.substr(start);
    len = substr.length();
    num = strtol(substr.c_str(),NULL,10);
    start = version.size();
  }
  return num;
}
};