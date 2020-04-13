/**
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Simple. For each cell of value 1, look to its left,right, up and down values. If they are zero, add 1 to count.
We can also use direction array {0,1} {1,0} {0,-1} {-1,0}.

**/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int count=0;
        int r=grid.size();
        int c=grid[0].size();
        int row,col;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    row=i;
                    col=j-1;
                    if(row>=0 and row<r and col<c and col>=0)
                        grid[row][col]==0 ? ++count : 0;
                    else if(col==-1)
                        count++;
                    
                    row=i-1;
                    col=j;
                    if(row>=0 and row<r and col<c and col>=0)
                        grid[row][col]==0 ? ++count : 0;
                    else if(row==-1)
                        count++;
                    
                    row=i;
                    col=j+1;
                    if(row>=0 and row<r and col<c and col>=0)
                        grid[row][col]==0 ? ++count : 0;
                    else if(col==c)
                        count++;
                    
                    row=i+1;
                    col=j;
                    if(row>=0 and row<r and col<c and col>=0)
                        grid[row][col]==0 ? ++count : 0;
                    else if(row==r)
                        count++;
                }
            }
        }
        return count;
    }
};
// 3
// 3
// 3
// 2
// 2
// 3
