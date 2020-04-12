/**
Given an integer, write a function to determine if it is a power of two.

Using log2 function, we can find exponent of given number. Check the number==power of two of n.
**/

class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n<=0)
            return 0;
        int exp = ceil(log2(n));
        return n==pow(2,exp);
    }
};
