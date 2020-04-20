/**
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

At a given day, we should decide two things. One is to either buy a stock or do nothing. Secondly, sell a stock or do nothing.

**/



class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int hold = -prices[0]; // On day 1, if i buy this stock then my hold(balance) will be -ve of that price.
        int sell = 0; // If i sell on same day then net profit is 0.
        
        for(int price : prices)
        {
            hold = max(hold,sell-price); // The stock i am holding is better than buying the current stock. This means the stock you are holding is the minimum compared to the next one. hold will have the netprofit if sell-price is higher.
            sell = max(sell,hold+price-fee); // last net profit is more ?? or the profit we get by selling the stock is more.
        }
        return sell; // This is the final profit.
    }
};
