/**
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

References: 
https://www.youtube.com/watch?v=TLaGwTnd3HY
https://www.youtube.com/watch?v=_nCsPn7_OgI

Treat each substring's start and end indices as 2D array and save the results of each one and reuse it later.
**/


class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int len = s.size();
        if(len==0)
            return 0;
        int dp[len][len];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<len;i++)
            dp[i][i] = 1; //diagonals 
        
        for(int i=1;i<len;i++)
        {
            int start = 0;
            int end = i;
            while(end<len)
            {
                if(s[start]==s[end])
                    dp[start][end] = 2+dp[start+1][end-1]; // 2 characters match, so adding 2 with whatever is the longest subsequence between the start and end boundaries.
                else
                    dp[start][end] = max(dp[start][end-1],dp[start+1][end]);//If there is no match, then at this end boundary the longest subsequence will be same as whatever was calculated before it.
                start++;
                end++;
            }
        }
        return dp[0][len-1];
    }
};
