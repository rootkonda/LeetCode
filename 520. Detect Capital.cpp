/**
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Simple and straightforward. 97-122 (upper) 65-90 (lower)

**/

class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        if(word[0]>=97 and word[0]<=122)
        {
            int i=0;
            while(i<word.size() and word[i]>=97 and word[i]<=122)
                i++;
            if(i==word.size())
                return true;
            else
                return false;
        }
        if(word[0]>=65 and word[0]<=90)
        {
            if(word[1]>=65 and word[1]<=90)
            {
                int i=2;
                while(i<word.size() and word[i]>=65 and word[i]<=90)
                    i++;
                if(i==word.size())
                    return true;
                else
                    return false;
            }
            else
            {
                int i=1;
                while(i<word.size() and word[i]>=97 and word[i]<=122)
                    i++;
                if(i>=word.size())
                    return true;  
                else
                    return false;
            }
        }
        return false;
    }
};
