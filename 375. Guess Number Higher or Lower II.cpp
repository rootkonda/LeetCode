/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Everytime we guess a wrong number except for the last time -  How many ways are there in which we can do this ? Out of those ways what is the least/minimum amount required ?? This is the question asked.

https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84798/C%2B%2B_DP_Recursive_with-brief-explanation
*/

class Solution {
public:
    int helper(int start, int end, vector<vector<int>>& dp)
    {
        if(start>=end)
            return 0;
        if(dp[start][end])
            return dp[start][end];
        int ans = INT_MAX;
        for(int k=start;k<end;k++)
        {
            int sub = k+max(helper(start,k-1,dp),helper(k+1,end,dp));
            ans = min(ans,sub);
        }
        return dp[start][end] = ans;
    }
    int getMoneyAmount(int n) 
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return helper(1,n,dp);    
    }
};
