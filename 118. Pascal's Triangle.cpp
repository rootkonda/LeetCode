/**
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

Loop thru from 1 to numRows. For each value, create a vector initialized with 1's. After that, take the previous row and update
the current till numRows of that row.**/

**/



class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> row,prev;
        int i,j;
        
        for(int k=1;k<=numRows;k++)
        {
            vector<int> row(k,1);
            i=0;j=1;
            for(int m=1;m<k-1;m++)
                row[m]=ans[k-2][i++]+ans[k-2][j++];
            ans.push_back(row);
        }
        return ans;
    }
};
