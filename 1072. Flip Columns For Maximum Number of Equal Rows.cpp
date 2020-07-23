/*
Given a matrix consisting of 0s and 1s, we may choose any number of columns in the matrix and flip every cell in that column.  Flipping a cell changes the value of that cell from 0 to 1 or from 1 to 0.

Return the maximum number of rows that have all values equal after some number of flips.


https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/discuss/304007/C%2B%2BChinesefind-the-same-pattern-between-the-rows
https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/discuss/303761/C%2B%2B-Brute-Force

Count the number of rows having same pattern and that is our answer. In order to find the same pattern we have to find the rows which doesnt have same pattern,count them and subtract from total number of rows which will give us the number of rows matching the pattern. We have to repeatedly do this for the set of rows which have different pattern. Keep track of max answer.

In order to find the pattern we use xor of values. So if two cells have an XOR value and the rest of the cells should also result in same XOR if they have same pattern.
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) 
    {
        int ans = 0;
        while(mat.size()>ans)
        {
            vector<vector<int>> temp;
            for(auto i=1,j=0;i<mat.size();i++)
            {
                for(j=0;j<mat[i].size() and (mat[0][0]^mat[i][0])==(mat[0][j]^mat[i][j]);j++);
                if(j!=mat[i].size())
                    temp.push_back(mat[i]);
            }
            ans = max(ans,(int)(mat.size()-temp.size()));
            mat = temp;
        }
        return ans;
    }
};
