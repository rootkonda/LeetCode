/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Bottom-up approach. Each entry in dp array will have least number of perfect squares required to reach the target sum(n).
So we start from 1 and go upto n(given sum). After we calculate the minimum answer then add that to the dp array.


https://leetcode.com/problems/perfect-squares/discuss/71512/Static-DP-C%2B%2B-12-ms-Python-172-ms-Ruby-384-ms
*/

class Solution {
public:
    vector<int> dp {0};
    int numSquares(int n) 
    {
        while(dp.size()<=n)
        {
            int ways=INT_MAX;
            int m = dp.size();
            for(int i=1;(i*i)<=m;i++)
                ways = min(ways,dp[m-(i*i)]+1);
            dp.push_back(ways);
        }
        return dp[n];
    }
};
