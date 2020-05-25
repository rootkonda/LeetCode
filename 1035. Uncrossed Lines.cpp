/*

We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

Explanation
-----------
We have to think whether smaller inputs help us build answer for bigger inputs ?? If so, then the question belongs to Dynamic Programming(Bottom-Up). This Longest common subsequence problem fits that description so we can solve it using dynamic programming.

This is LCS problem based on integers, main flavor is based on strings.
*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) 
    {
        int n1 = (int)A.size();
        int n2 = (int)B.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(A[i]==B[j])
                    dp[i+1][j+1] = 1+dp[i][j];
                else
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[n1][n2];
    }
};
