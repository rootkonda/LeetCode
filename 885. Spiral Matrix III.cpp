/*
On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid. 

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 

Eventually, we reach all R * C spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.


https://leetcode.com/problems/spiral-matrix-iii/discuss/158970/C%2B%2BJavaPython-112233-Steps

Initially we start moving towards right, so x=0, y=1 - we stay in same row and move on to next column for right
x=-1, y=0 - For going down
x=0, y =-1 - For moving towards left
x=-1, y=0 - For moving towards up.

How many steps in each direction is determined by n, which is in the sequence 1,1,2,2,3,3

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) 
    {
        int dx=0,dy=1;
        vector<vector<int>> res{{r,c}};
        int tmp;
        for(int n=0;res.size()<rows*cols;n++)
        {
            for(int i=0;i<n/2+1;i++)
            {
                r+=dx,c+=dy;
                if(r>=0 and r<rows and c>=0 and c<cols)
                    res.push_back({r,c});
            }
            tmp=dx, dx=dy, dy=-tmp; // This logic is to change the direction
        }
        return res;
    }
};
