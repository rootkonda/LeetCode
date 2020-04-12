/**
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Follow up: Could you solve it without loops/recursion?

Approach:

To find if a number is a power of four or any power exponent. We can use log2 function. Formula is log2(number)/log2(exponent). Make sure you use float or double to store the result.
**/

class Solution {
public:
    bool isPowerOfFour(int num) 
    {
        if(num<=0)
            return 0;
        float exp = (log2(num)/log2(4));
        return ceil(exp)-exp==0;
    }
};
