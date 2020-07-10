/*
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?


*/

class Solution {
public:
    int ans=0;
    int integerReplacement(int n) 
    {
        if(n==1)
            return ans;
        if(n==3) // 3->2->1 2-steps
            return ans+=2;
        if(n==INT_MAX) // Going n+1 route results in 32 and n-1 route in 33 so its a special case as n+1 overflows integer
            return 32;
        ans++;
        if(n&1) // When it is odd
        {
            if((n+1)%4==0) // %4 is because it will reduces the n more when it is even and %4
                integerReplacement(n+1);
            else // when n+1 is not divisible by 4
                integerReplacement(n-1);
        }
        else // when n is even
            integerReplacement(n/2);
        return ans;
    }
};
