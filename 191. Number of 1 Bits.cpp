/**
Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

Simple. Use bitset and its count() function to return number of 1's
**/

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        bitset<32> bits(n);
        return bits.count();
    }
};
