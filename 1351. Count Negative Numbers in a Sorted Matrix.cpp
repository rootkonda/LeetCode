/**
Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

Simple.
**/


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int rlen=grid.size();
        int clen=grid[0].size();
        int count=0;
        for(int i=0;i<rlen;i++)
        {
            for(int j=0;j<clen;j++)
            {
                if(grid[i][j]<0)
                {
                    count+=(clen-j);
                    break;
                }
            }
        }
        return count;
    }
};
