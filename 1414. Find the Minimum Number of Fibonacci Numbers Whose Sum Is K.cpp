/*
Given the number k, return the minimum number of Fibonacci numbers whose sum is equal to k, whether a Fibonacci number could be used multiple times.

The Fibonacci numbers are defined as:

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 , for n > 2.
It is guaranteed that for the given constraints we can always find such fibonacci numbers that sum k.

https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/discuss/585577/C%2B%2B-Greedy
https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/discuss/585632/Easy-Prove
Find the closest/adjacent fibo number,subtract this number from n and recursively do this until n becomes < 2 and for every recursion add 1.

*/


class Solution {
public:
    int findMinFibonacciNumbers(int k) 
    {
        if(k<2)
            return k;
        int a=1,b=1;
        while(b<=k)
        {
            swap(a,b);
            b+=a;
        }
        return 1+findMinFibonacciNumbers(k-a);
    }
};
