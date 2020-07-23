/*

Given a rows * columns matrix mat of ones and zeros, return how many submatrices have all ones.

In order to find the rectangle first we start at a cell and keep moving right until we find 0 and when we find 0 then we set a bound to that column and whenever we see 0 we change our bound
so it means we are setting boundaries.

*/
class Solution {
public:
    int ans = 0;
    int rows=0;
    int cols=0;
    void count(vector<vector<int>>& mat,int r, int c)
    {
        int col_bound=cols;
        for(int i=r;i<rows;i++)
        {
            for(int j=c;j<col_bound;j++)
            {
                if(mat[i][j])
                    ans++;
                else
                    col_bound=j;
            }
        }
    }
    int numSubmat(vector<vector<int>>& mat) 
    {
        rows = mat.size();
        cols = mat[0].size();
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                count(mat,i,j);
        return ans;
    }
};

