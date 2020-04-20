/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

**/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    { 
        int days = prices.size();
        if(days == 0)
            return 0;
        int dp[days][2];
        dp[0][0] = 0; // Day 0 having no stocks in hand.(Two ways: Do no buy anything or sell what we have in hand that makes it 0 stocks.
        dp[0][1] = -prices[0];// Day 0 with 1 stock in hand.(Two ways: If you already bought a stock before then do not buy it or if we want to buy newly then we can buy only if stock was sold two days ago i.e. cooldown 1 day.
        
        for(int day=1;day<days;day++)
        {
            dp[day][0] = max(dp[day-1][0],dp[day-1][1]+prices[day]);
            dp[day][1] = max(dp[day-1][1],(day==1 ? 0 : dp[day-2][0])-prices[day]);
        }
        return dp[days-1][0];
    }
};
