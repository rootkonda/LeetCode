/**
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

1. First use the kadane's algorithm to find the maximum subarray sum.
2. Find the sum of all elements.
3. Now run another loop to and find the maximum subarray sum when all the elements are inverted.
4. Next, add the actual sum with max subarray sum.
5. This logic wont work when there are all -ve numbers because sum+ans2 leads to zero. If thats the case, we should return the max subarray sum of actual array.

Example:
1. 5 -3 5 = 7 (total) 5+5 = 10 (actual max subarray sum) but thats reduced because of -3 subarray.
2. Invert -5 3 -5 = max subarray sum is 3
3. so total (7) + 3 = 10, which is the answer when there is a circular subarray sum.
 
**/

class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& A) 
    {
        int len = A.size();
        int ans1 = A[0]; 
        int ans2 = A[0];
        int curr = A[0];
       
        for(int i=1;i<len;i++)
        {
            curr = max(A[i],curr+A[i]);
            ans1 = max(ans1,curr);
        }
        curr = -1*A[0];
        ans2 = -1*A[0];
        int sum = accumulate(A.begin(),A.end(),0);
        for(int i=1;i<len;i++)
        {
            int val = (-1*A[i]);
            curr = max(val,curr+val);
            ans2 = max(ans2,curr);
        }
        if (sum+ans2==0)
            return ans1;
        return max(ans1,ans2+sum);
    }
};


// 
