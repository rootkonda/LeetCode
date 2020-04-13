/**

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

https://www.youtube.com/watch?v=BXCEFAzhxGY

Idea is to use KMP algorithm and calculate the length of prefix at every character position. The length of a string has to be a even sized. so Take the length of longest prefix available in KMP array and mod it with total length should give us zero.
**/


class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        int len=s.length();
        vector<int> kmp(len,0);
        int left=0,right=1;
        
        while(right<len)
        {
            while(s[left]!=s[right] and right<len)
            {
                 if(left-1>=0)
                     left=kmp[left-1];
                 else
                 {
                     left=0;
                     right++;
                 }
            }
            if(s[left]==s[right])
            {
                kmp[right]=left+1;
                left++;
                right++;
            }
        }
        if(len%(len-kmp[len-1])==0 and kmp[len-1]!=0)
            return true;
        return false;
    }
};
