/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Approach:

Two pointers - front and back. Every time check if both pointers are either digit or alphabet otherwise move the respective
pointers until we find it.
**/

class Solution {
public:
    bool isPalindrome(string s) 
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);  
        for(int i=0,j=s.length()-1;i<j;)
        {
            while(!(isalpha(s[i]) or isdigit(s[i])))
            {
                i++;
                if(i>=s.length())
                    return true;
            }
               
            while(!(isalpha(s[j]) or isdigit(s[j])))
            {
                j--;
                if(j>=s.length())
                   return true;
            }
               
            if(s[i]!=s[j] && i<j)
               return false;
            i++;
            j--;
        }
        return true;
    }
};
