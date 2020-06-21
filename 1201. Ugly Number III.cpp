/*
Write a program to find the n-th ugly number.

Ugly numbers are positive integers which are divisible by a or b or c.
Constraints:

1 <= n, a, b, c <= 10^9
1 <= a * b * c <= 10^18
It's guaranteed that the result will be in range [1, 2 * 10^9]


This problem can easily solved by binary-search by defining the predicate: "Given N, how many numbers upto N are divisible by A or B or C"

The predicate can be evaluated by inclusion-exclusion principle:

No. of numbers upto N divisible by A = N/A;
No. of numbers upto N divisible by B = N/B;
No. of numbers upto N divisible by C = N/C;

No. of numbers upto N divisible by both A and B = N / lcm(A, B);
No. of numbers upto N divisible by both B and C = N / lcm(B, C);
No. of numbers upto N divisible by both A and C = N / lcm(A, C);

No. of numbers upto N divisible by all A, B and C = N / lcm(A, B, C);
Furthermore LCM(A, B) can be computed as LCM(A, B) = (A*B) / GCD(A, B)

https://www.topcoder.com/community/competitive-programming/tutorials/binary-search
https://leetcode.com/problems/ugly-number-iii/discuss/387780/JavaC%2B%2B-Binary-Search-with-Venn-Diagram-Explain-Math-Formula
*/



typedef long long ll;

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        int left=0, right=2e9, ans=0;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(count(mid,a,b,c)>=n)
            {
                ans = mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        return ans;
    }
    ll count(ll num,ll a, ll b, ll c)
    {
        return (num/a+num/b+num/c-
                num/lcm(a,b)-
                num/lcm(a,c)-
                num/lcm(b,c)+
                num/lcm(a,lcm(b,c)));
    }
    ll lcm(ll a, ll b)
    {
        return (a*b)/__gcd(a,b);
    }
};
