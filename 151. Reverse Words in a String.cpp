/*
Given an input string, reverse the string word by word.

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.


*/


class Solution {
public:
    string reverseWords(string s) 
    {
         int i;
        //First non-whitespace character from the beginning of string
        for(i=0;i<s.size() and ' '==s[i];i++);
        int start = i;
        
        //First non-whitespace character from the end of string
        for(i=s.size()-1; i>=0 and ' '==s[i];i--);
        int end = i;
        
        //Unwanted spaces between words should also be removed
        int len=0;
        for(i=start;i<=end;i++)
        {
            if(s[i]==' ' and s[i-1]==' ')
                continue;
            s[len++] = s[i];
        }
        s.erase(s.begin()+len,s.end());
        reverse(s.begin(),s.end());
        
        for(i=0,start=0;i<len;i++)
        {
            if(s[i]==' ')
            {
                reverse(s.begin()+start,s.begin()+i);
                start = i+1;
            }
        }
        // Last word
        reverse(s.begin()+start,s.end());
        return s;
    }
};
