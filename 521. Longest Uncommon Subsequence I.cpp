/**
Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Approach - Store the characters of a into stack and run loop on string b. If there is a match in stack remove it and keep track of count of characters removed. If all characters are removed from stack then it is a copy of string a.
**/

class Solution {
public:
    int findLUSlength(string a, string b)
    {
        stack<char> stk;
        
        for(auto c : a)
            stk.push(c);
        
        int ans=stk.size();
        if(ans>b.size())
            return ans;
        else if(ans<b.size())
            return b.size();
        int count=0;
        for(int i=b.size()-1;i>=0;i--)
        {
            if(!stk.empty())
            {
                if(stk.top()==b[i])
                    count++;
                stk.pop();
            }
        }
        if(count==b.size())
            return -1;
        return ans;
    }
};
