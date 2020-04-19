/**
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.



**/



class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int rlen = text1.size();
        int clen = text2.size();
        
        int dp[rlen][clen];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<rlen;i++)
        {
            for(int j=0;j<clen;j++)
            {
                if(text1[i]==text2[j])
                    dp[i][j] = 1 + (i>0 and j>0 ? dp[i-1][j-1] : 0);
                else
                {
                    int left = (j>0 ? dp[i][j-1] : 0);
                    int top = (i>0 ? dp[i-1][j] : 0);
                    
                    dp[i][j] = max(left,top);
                }
            }
        }
        return dp[rlen-1][clen-1];
        
    }
};
