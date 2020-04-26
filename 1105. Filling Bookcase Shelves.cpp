/**
We have a sequence of books: the i-th book has thickness books[i][0] and height books[i][1].

We want to place these books in order onto bookcase shelves that have total width shelf_width.

We choose some of the books to place on this shelf (such that the sum of their thickness is <= shelf_width), then build another level of shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down.  We repeat this process until there are no more books to place.

Note again that at each step of the above process, the order of the books we place is the same order as the given sequence of books.  For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.


1. Two for loops, first loop runs from 1 to N and second loop runs from backwards.(Bottom-Up)
2. dp[] array stores the minimum height at a given index of books.
3. Say i=3,then j=3 - It starts from calculating the max height and finding the total height using dp array. Finally, the minimum total height is maintained at index i of dp array.

**/



class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) 
    {
        int len = books.size();
        vector<int> dp(len+1,0);
        
        for(int i=1;i<=len;i++)
        {
            int h=0,w=0;
            dp[i] = INT_MAX;
            for(int j=i;j>0;--j)
            {
                w+=books[j-1][0];
                if(w>shelf_width)
                    break;
                h = max(h,books[j-1][1]);
                dp[i] = min(dp[i],h+dp[j-1]);
            }
        }
        return dp[len];
            
    }
};
