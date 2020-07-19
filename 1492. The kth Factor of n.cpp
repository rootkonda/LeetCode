/*
Given two positive integers n and k.

A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

https://leetcode.com/problems/the-kth-factor-of-n/

*/

class Solution {
public:
    int kthFactor(int n, int k) 
    {
        int d;
        for(d=1;d<=n/2;d++) // n/2 is obvious when we look at the pattern that n/2 number is the second max factor from last factor(n itself)
        {
            if(n%d==0 and --k==0)
                return d;
        }
        return k==1 ? n : -1; // Remember that only prime numbers have exactly 2 factors so if n is prime then k==1 then return n or else k is greater than total number of factors so return -1.
    }
};
