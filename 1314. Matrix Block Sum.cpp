/**
Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.

Reference: https://www.youtube.com/watch?v=58YLH16lf1E

Remember prefix sum always starts with 0 so for an element at i,j in given array, the prefix sum is at i+1,j+1. Hence when you subtract K from original index i, to get the corresponding index, we subtract again i.e. i-k-1 or j-k-1.
**/


class Solution 
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
    {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> pref(row+1,vector<int>(col+1,0));
        vector<vector<int>> answer(row,vector<int>(col));
        
        //calculate prefix sum for 2D array
        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                pref[i][j] = mat[i-1][j-1]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
        
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                int full = pref[min(row,i+K)][min(col,j+K)];
                int top  = pref[max(0,i-K-1)][min(col,j+K)];
                int left = pref[min(row,i+K)][max(0,j-K-1)];
                int edge = pref[max(0,i-K-1)][max(0,j-K-1)];
                
                answer[i-1][j-1] = full-top-left+edge;
            }
        }
        return answer;
    }
};
