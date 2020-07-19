/*
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

Use XOR and mask bit to change 0 to 1 or 1 to 0.
Find the cibt from LSB and keep fliping the a and b bits using mask until we make a|b==c
*/

class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        int mask=1;
        int ans = 0;
        while((a | b) != c)
        {
            int cbit = c & mask;
            if(cbit and !(a&mask or b&mask)) 
            {
                a^=mask;
                b^=mask;
                ans++;    
            }
            else if(!cbit)
            {
                if(a&mask)
                {
                    a^=mask;
                    ans++;
                }
                if(b&mask)
                {
                    b^=mask;
                    ans++;
                }
            }   
            mask<<=1;
        }
        return ans;
    }
};

/*

Solution - 2
------------
Step 1: a | b is what we have while c is what we want. An XOR operation finds all different bits, i.e. (a | b) ^ c sets the bits where flip(s) is needed. Then we count the set bits.
Step 2: There is only one case when two flips are needed: a bit is 0 in c but is 1 in both a and b. An AND operation finds all common 1 bits, i.e. a & b & ((a | b) ^ c) sets the common 1 bits in a, b and the must-flip bits found in Step 1.

https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/discuss/479998/C%2B%2B-bitwise-xor-solution-1-line
*/

int minFlips(int a, int b, int c) 
{
    return popcount((a | b) ^ c) + popcount(a & b & ((a | b) ^ c));
}
