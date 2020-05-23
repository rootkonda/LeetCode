/*

Explanation:

This is a recursive function. To calculate a minimum split into triangle pices we select one edge between to vertex (let it be an edge between first and last vertex). And draw all possible triangles with this edge. It will be N-2 triangles, because there are N-2 vertexes beside first and last one. In this funcion we split the poigon in three sub poligons: prev poligon, triange that used this edge, and future poligion.
For eaxmple if we have 5 vertexes with indices 0, 1, 2, 3, 4, it's could be prev poligon: [0,1,2], triange: [0,2,4], future poligion: [2,3,4]. Each of this poligons could be send in recursive call, or calculated inplace if it has 3 sides.

https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/571156/Ruby-100.-Explanation.-Image.
https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/558814/Easy-Solution-With-Explanation-or-BOTTOM-UP-and-TOP-BOTTOM-or-C%2B%2B
*/


class Solution {
public:
    
    int helper(int start,int end,vector<int>& A,vector<vector<int>>& dp)
    {
        if(dp[start][end]!=-1)
            return dp[start][end];
        if(end-start<2)
            return 0;
        if(end-start==2)
        {
            dp[start][end] = (A[start]*A[start+1]*A[end]); 
            return dp[start][end];
        }
        int ans = INT_MAX;
        for(int i=start+1;i<end;i++)
        {
            int a = helper(start,i,A,dp);
            int b = helper(i,end,A,dp);
            int curr = (A[start]*A[i]*A[end])+a+b;
            ans = min(ans,curr);
        }
        dp[start][end] = ans;
        return ans;
    }
    int minScoreTriangulation(vector<int>& A) 
    {
        int n = (int)A.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(0,n-1,A,dp);     
    }
};
