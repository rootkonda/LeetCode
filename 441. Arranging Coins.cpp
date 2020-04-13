/**
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Two ways:
1. This is an example of arthimetic progression. For a given number how many are possible ? -1+sqrt(1+8n)/2
2. As mentioned below.
**/

class Solution {
public:
    int arrangeCoins(int n) 
    {
        long a=n;
        long b=sqrt(a*2);
        if(a*2 < b*(b+1))
            return b-1;
        else
            return b;
        
    }
};
