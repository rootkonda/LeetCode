/**
Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

1. For every element find the number of subarrays where this element is minimum.
2. Number of elements larger than current element in the left * Number of elements larger than to the right of current element
3. So the formula is sum+=A[i]*left[i]*right[i];

**/

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) 
    {
        int len = A.size();
        int left[len],right[len];
        stack<pair<int,int>> sl,sr;
        int ans = 0;
        for(int i=0;i<len;i++)
        {
            int count = 1;
            while(!sl.empty() and sl.top().first>A[i])
            {
                count+=sl.top().second;
                sl.pop();
            }
            sl.push({A[i],count});
            left[i] = count;
        }
        
        for(int i=len-1;i>=0;i--)
        {
            int count = 1;
            while(!sr.empty() and sr.top().first>=A[i])
            {
                count+=sr.top().second;
                sr.pop();
            }
            sr.push({A[i],count});
            right[i]=count;
        }
        
        for(int i=0;i<len;i++)
            ans = (ans+A[i]*left[i]*right[i])%1000000007;
            
        return ans;
    }
};
