/**
Given an array, strs, with strings consisting of only 0s and 1s. Also two integers m and n.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

For each string, first count the zeroes and ones.
Next, for given m and n update all the possible combinations of 1's and 0's after considering the current string into account.
For the second string, check for the previous string's corresponding combination should also have one.

          dp[i-zeroes][j-ones]+1.  ----  This will check the possible combinations after consuming each string earlier.
We have two choices: either select the current string or don't depends on the maximum count. If we do not select the current string, then the previous count stays the same.


**/

class Solution 
{
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int len = strs.size();
        int ans = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(auto str : strs)
        {
            int zeroes = 0;
            int ones = 0;
            
            for(int i=0;i<str.size();i++)
            {
                if(str[i]=='0')
                    zeroes++;
                else
                    ones++;
            }
            for(int i=m;i>=zeroes;i--)
            {
                for(int j=n;j>=ones;j--)
                {
                    dp[i][j] = max(dp[i][j],dp[i-zeroes][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};




 
