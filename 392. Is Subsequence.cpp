/**
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Approach:
Start comparing the first character in t until you find it. When we find it, move to next character.

**/
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int j=-1;
        for(int i=0;i<s.length();i++)
        {
            j++;
            while(j<t.length())
            {
                if(s[i]==t[j])
                    break;
                j++;
            }
            if(j==t.length())
                return false;
        }
        return true;
    }
};
