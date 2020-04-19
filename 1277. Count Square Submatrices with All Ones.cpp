/**
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Reference:
https://www.techiedelight.com/find-size-largest-square-sub-matrix-1s-present-given-binary-matrix/
https://www.youtube.com/watch?v=_Lf1looyJMU&t=22s

For a point(i,j) at bottom right corner of a bigger square of size k, the immediate subsquare should be atleast k-1. Hence, get the minimum of all sides and add 1 to it. Adding 1 because we have to include i,j as a square. This means there is a minimum square of side 1 or say k exists around the point i,j and adding 1 to that minimum square side will increase the side by 1.

**/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int dp[row+1][col+1];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(matrix[i-1][j-1]==1)
                {
                    dp[i][j] = 1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                    ans+=dp[i][j];
                }   
            }
        }
        return ans;
    }
};
