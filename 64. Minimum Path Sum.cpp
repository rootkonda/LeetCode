/**
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Idea is to store the minimum path sum at every point. Whenever another path comes to already calculated path, then take the minium of existing sum and new sum and assign the minimum.
**/



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(grid.size()==0)
            return 0;
        int rlen = grid.size();
        int clen = grid[0].size();
        int dp[rlen][clen];
        memset(dp,-1,sizeof(dp));
        dp[0][0]=grid[0][0];
        int sum = 0;
        for(int i=0;i<rlen;i++)
        {
            for(int j=0;j<clen;j++)
            {
                if(j+1<clen)
                {
                    sum = dp[i][j]+grid[i][j+1];
                    if(dp[i][j+1]!=-1)
                        dp[i][j+1] = min(dp[i][j+1],sum);
                    else
                        dp[i][j+1] = sum;
                }
                if(i+1<rlen)
                {
                    sum = dp[i][j]+grid[i+1][j];
                    if(dp[i+1][j]!=-1)
                        dp[i+1][j] = min(dp[i+1][j],sum);
                    else
                        dp[i+1][j] = sum;
                }
            }
        }
        return dp[rlen-1][clen-1];
    }
};
