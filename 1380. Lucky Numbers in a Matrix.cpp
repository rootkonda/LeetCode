/**
Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

Find the min element in the row and insert it in lucky 2D array. Find max element and its col,row and check both values are same.
**/

class Solution 
{
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int rowlen=matrix.size();
        int collen=matrix[0].size();
        vector<vector<int>> lucky(rowlen,vector<int>(collen,-1));
        int min=-1,max=-1;
        int row, col;
        for(int i=0;i<rowlen;i++)
        {
            min=matrix[i][0]+1;
            for(int j=0;j<collen;j++)
            {
                if(min>matrix[i][j])
                {
                    min=matrix[i][j];
                    row=i;
                    col=j;
                }
            }
            lucky[row][col]=min;
        }
        for(int i=0;i<collen;i++)
        {
            max=matrix[0][i]-1;
            for(int j=0;j<rowlen;j++)
            {
                if(max<matrix[j][i])
                {
                    max=matrix[j][i];
                    row=j;
                    col=i;
                }
            }
            if(lucky[row][col]==max)
                ans.push_back(max);
        }
        return ans;
    }
};
