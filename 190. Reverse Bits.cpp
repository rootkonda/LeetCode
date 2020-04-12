/**
Reverse bits of a given 32 bits unsigned integer.

Simple but learned new things. 
1. uint32_t
2.bitset<32>
Just start the loop from 31st bit to bit 0 and reverse bits.
**/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t ans;
        bitset<32> bits(n),res;
        int idx=0;
        for(int i=31;i>=0;i--)
            res[idx++]=bits[i];
        ans=res.to_ulong();
        return ans;
        
    }
};
