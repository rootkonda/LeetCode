/*
We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup (250ml) of champagne.

Then, some champagne is poured in the first glass at the top.  When the top most glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has it's excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.


Similar to pascal triangle
*/


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        vector<vector<double>> dp(query_row+2,vector<double>(query_row+2,0.0));
        dp[0][0] = poured;      
        for(int row=0;row<=query_row;row++)
        {
           for(int glass=0;glass<=row;glass++)
           {
                if(dp[row][glass]>1)
                {
                    dp[row+1][glass]+=(dp[row][glass]-1)/2.0;
                    dp[row+1][glass+1]+=(dp[row][glass]-1)/2.0;
                    dp[row][glass]=1;
                }
           }
        }
        return dp[query_row][query_glass];
    }
};
