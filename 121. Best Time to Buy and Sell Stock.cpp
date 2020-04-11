/**
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Approach:

Start from the back. For the last element the selling price will be zero. So the profit will be none/-ve. For the next element,
set the maximum value so far as sell price.
**/


class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans=0,sell;
        int mx=0,profit;
        int len=prices.size();
        if(len==0)
            return 0;
        for(int i=len-1;i>=0;i--)
        {
            sell=mx;
            mx=max(mx,prices[i]);
            profit=sell-prices[i];
            if(profit>ans)
                ans=profit;
        }
        return ans;
    }
};
