/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

This is the bottom-up solution.
Start taking from last two rows and calculate the adjacent sum for each item in the row before last and just repeat the same using the just found answer.
Adjacent means if we choose an element at ith index in a row then in the next row you can choose i or i+1th element.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) 
    {
        vector<int> ans = tri[tri.size()-1];
        for(int i=tri.size()-2;i>=0;i--)
        {
            for(int j=0;j<tri[i].size();j++)
               ans[j] = tri[i][j] + min(ans[j],ans[j+1]);
        }
        return ans[0];
    }
};
