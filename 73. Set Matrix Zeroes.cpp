/*

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

My idea is simple: store states of each row in the first of that row, and store states of each column in the first of that column. Because the state of row0 and the state of column0 would occupy the same cell, I let it be the state of row0, and use another variable "col0" for column0. In the first phase, use matrix elements to set states in a top-down way. In the second phase, use states to set matrix elements in a bottom-up way.


*/
class Solution {
public:
    int m,n;
    void setZeroes(vector<vector<int>>& mat) 
    {
        m = mat.size();
        if(m==0)
            return;
        n = mat[0].size();
        int col=1;
        for(int i=0;i<m;i++)
        {
            if(mat[i][0]==0)
                col=0;
            for(int j=1;j<n;j++)
            {
                if(mat[i][j]==0)
                    mat[i][0] = mat[0][j] = 0;
            }
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=1;j--)
            {
                if(mat[i][0]==0 or mat[0][j]==0)
                    mat[i][j] = 0;
            }
            if(col==0)
                mat[i][0] = 0;
        }
    }
};
