/**


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
