/**

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
Note:

The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

Two ways:
1. Use bitset and flip method to flip the bits.
2. Find the number of bits using log2(num)+1 and then run a loop from 0 to number of bits. XOR with 1<<i.
**/

class Solution 
{
public:
    int findComplement(int num) 
    {
        int bits=log2(num)+1;
        for(int i=0;i<bits;i++)
            num = num ^ (1<<i);
        return num;
    }
};
