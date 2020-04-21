/**
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
**/



class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        bool alex = true;
        int acount = 0;
        int lcount = 0;
        int left = 0,right = piles.size()-1;
        while(left < right)
        {
            int sum = 0;
            if(piles[left]-piles[left+1] > piles[right]-piles[right-1])
            {
                sum=piles[left];
                left++;
            }    
            else
            {
                sum=piles[right];
                right--;
            }
            if(alex)
                acount+=sum;
            else
                lcount+=sum;
            alex = !alex;
        }
        lcount+=piles[left];
        if(acount > lcount) Since the values are always even, so the result is always true. In case of odd number of piles, then this will correctly return the true or false values. And also lcount and acount gives the accurate number of stones collected.
            return acount;
        return lcount;
    }
};
    
