/**
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Approach:
1. Go by ranges of size 10. start as 1 and end as 10 keep looping until the given number is within start and end.
2. Binary Search with low as 1 and high as n.
**/

class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        long long l=1,r=10;
        while(num>=(r*r))
        {
            l=r;
            r+=10;
        }
        for(long long i=l;i<=r;i++)
        {
            if((i*i)==num)
                return true;
        }
        return false;
    }
};
