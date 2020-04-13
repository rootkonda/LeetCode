/**
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.

Game of divide and mod. 
1. (i+(j+k)/colsize)%rowsize - gives us row position, when shifted k times.
2. (j+k)%colsize - gives us col position, when shifted k times.
**/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int i,j;
        int rowlen=grid.size();
        int collen=grid[0].size();
        vector<vector<int>> curr(rowlen,vector<int>(collen,0));
        if(k%(rowlen*collen)==0 or k==0)
            return grid;
        
        for(i=0;i<rowlen;i++) 
          for(j=0;j<collen;j++) 
            curr[(i+(j+k)/collen)%rowlen][(j+k)%collen]=grid[i][j];
        
        return curr;
    }
};
