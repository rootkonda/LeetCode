/**
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

1. Usage of unsigned integer to keep the carry when doing left shift.
2. AND both a and b to get the carry bits.
3. XOR a and b means like addition.
4. << left shift the carry bit so that it becomes a carry for the next two bits.
**/

class Solution {
public:
    int getSum(int a, int b) 
    {
        while(b!=0)
        {
            unsigned int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};
