/*

Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)

A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.

Return the number of land squares in the grid for which we cannot walk off the boundary of the grid in any number of moves.

Note:

1 <= A.length <= 500
1 <= A[i].length <= 500
0 <= A[i][j] <= 1
All rows have the same size.


*/


class Solution {
public:
    int count = 0;
    int m,n;
    vector<vector<int>> directions = {{-1,0},{0,1},{0,-1},{1,0}};
    void helper(int row, int col, vector<vector<int>>& A)
    {
        A[row][col] = -1; // change the value to -1 to avoid redoing the work.
        for(auto dir : directions)
        {
            int r = row+dir[0];
            int c = col+dir[1];
            if(r>=0 and r<m and c>=0 and c<n)
            {
                if(A[r][c]==1)
                    helper(r,c,A);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& A) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        m = (int)A.size();
        n = (int)A[0].size();
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if((row==0 or row==m-1 or col==0 or col==n-1) and A[row][col]) // change all 1's connected to the edges to -1
                    helper(row,col,A);
            }
        }
        
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(A[row][col]==1) // Whatever 1's are left count them
                    count++;
            }
        }
        return count;
    }
};
