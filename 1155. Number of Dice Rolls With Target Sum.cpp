/*
You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

*/


class Solution {
public:
    const int MOD = 1e9+7;
    int numRollsToTarget(int d, int f, int target) 
    {
        vector<vector<int>> dp(d+1,vector<int>(target+1,0));
        dp[0][0] = 1; // Because with dice 1 and we can make sum 1 in 1 way
        for(int dice=1;dice<=d;dice++)
        {
            for(int t=1;t<=target;t++)
            {
                for(int face=1;face<=f;face++)
                {
                    if(t>=face)
                        dp[dice][t] = (dp[dice][t]%MOD + dp[dice-1][t-face]%MOD)%MOD;
                }
            }
        }
        return dp[d][target];
    }
};
