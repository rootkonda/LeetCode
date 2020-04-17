/**
Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  (For clarification, the L-length subarray could occur before or after the M-length subarray.)

Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:

0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
0 <= j < j + M - 1 < i < i + L - 1 < A.length.

1. Calculate the prefix sum and keep it in the same array.
2. Initialize the lmax as prefix sum upto L-1
3. Initialize the Mmax as prefix sum upto M-1
4. If the total sum of L+M-1 is bigger then that is the answer so assign res = A[L+M-1], this is the sum of elements from 0-L and L-M it means sum of elements from 0-L+M-1.
5. Two scenarios - M can occur before L or vice versa. So we have two maximums lmax and mmax.
6. Each time we find the lmax and calculate result maximum by getting Msum and vice versa.
**/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M)
    {
        for(int i = 1; i < A.size(); i++)
            A[i] += A[i-1];
        int res = A[L+M-1], Lmax = A[L-1], Mmax = A[M-1];
        for(int i = L + M; i < A.size(); i++) 
        {
            Lmax = max(Lmax, A[i-M]-A[i-M-L]);
            Mmax = max(Mmax, A[i-L]-A[i-M-L]);
            res = max(res, A[i]-A[i-M] + Lmax); 
            res = max(res, A[i]-A[i-L] + Mmax); 
        }
        return res;
    }
};
