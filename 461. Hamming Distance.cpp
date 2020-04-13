/**
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.
Note:
0 ≤ x, y < 231.

Two ways:

1. First XOR two numbers and then use bitset to find the count of 1's.
2. First XOR two numbers and then num%2==1 and num/=2 repeatition will give the count of 1's.
**/


class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {
        int num=x^y;
        int count=0;
        while(num!=0)
        {
            if(num%2==1)
                count++;
            num/=2;
        }
        return count;
    }
};
