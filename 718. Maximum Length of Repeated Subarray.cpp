/**
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Approach is to store the number of equal elements at i and j of both arrays. Find the maximum value every time we calculate dp[i][j].

**/

class Solution
{
public:
    int findLength(vector<int>& A, vector<int>& B)
    {
        int ans = 0;
        int dp[A.size()][B.size()];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                if(A[i]==B[j])
                {
                    dp[i][j] = (i-1>=0 and j-1>=0) ? dp[i-1][j-1]+1 : 1;
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};
