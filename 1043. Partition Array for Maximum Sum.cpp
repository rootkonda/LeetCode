/*
Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) 
    {
        int n = A.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--) //Start from the back and keep track of max at every element.
        {
            int mx=0;
            for(int j=i;j<i+K and j<n;j++)
            {
                mx = max(mx,A[j]);
                dp[i] = max(dp[i],(j-i+1)*mx+dp[j+1]); // At every ith index we will have max sum. dp[j+1] is to add the max sum we gained after the current the element.
            }
        }
        return dp[0];
    }
};

