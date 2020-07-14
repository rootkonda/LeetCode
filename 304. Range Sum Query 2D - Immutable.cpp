/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
*/
class NumMatrix {
public:
    int r=0,c=0;
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) 
    {
        r=matrix.size();
        if(r!=0)
            c=matrix[0].size();
        if(r!=0 and c!=0)
        {
            dp.resize(r+1,vector<int>(c+1,0));
        
            for(int i=1;i<=r;i++)
            {
                for(int j=1;j<=c;j++)
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1]+matrix[i-1][j-1]-dp[i-1][j-1];    
                }
            }
        }
        
    }
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        if(r==0 or c==0)
            return 0;
        row1++;
        col1++;
        row2++;
        col2++;
        return (dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1]);    
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
