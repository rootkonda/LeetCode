/**

Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Approach:

As many transactions are possible so we can just pick pair of profits at a time and calculate the total profit.
**/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int len=prices.size();
        int maxprofit=0;
        if(len==0)
            return 0;
        for(int i=1;i<len;i++)
        {
            if(prices[i-1]<prices[i])
                maxprofit+=prices[i]-prices[i-1];
        }
        return maxprofit;
    }
};
