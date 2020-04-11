/**
  Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

  If the last word does not exist, return 0.

  Note: A word is defined as a maximal substring consisting of non-space characters only.
  
  Approach:
  
  Start from the last character and count until we see a space character. When there is a space and count>0 then return count.**/


class Solution {
public:
    int lengthOfLastWord(string s) 
    {
         int count=0;
         for(int i=s.length()-1;i>-1;i--)
         {
             if(s[i]!=' ')
                 count++;
             else if(count>0)
                 break;
         }
         return count;
    }
};
