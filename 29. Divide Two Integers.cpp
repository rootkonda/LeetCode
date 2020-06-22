/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.


1. If divisor is 1 just return the dividend.
2. If dividend is INT_MIN and divisor is -1 then return INT_MAX because INT_MIN is -ve and -1 is -ve so answer becomes +ve MAX value. Hence return INT_MAX.
3. Find out the sign for the answer. 
4. -ve numbers are stored in 2's complement form. If dividend is -ve, then convert it into +ve unsigned integer by using ~(bit-wise complement) plus 1 on unsigned int(we get by typecasting). This is the way to convert 2's complement to unsigned integer. We do same for divisor as well.
5. Key idea about quotient is - How many times we can subtract divisor from dividend until it becomes -ve. That many times is our quotient. In order to find out this we use left shift bitwise operator on given divisor and keep shifting left until the divisort becomes greater than dividend. We also use counter to keep track of how many divisors are there.
6. When divisor is greater than dividend, we have to right shift the counter by 1 to take the previous value because it crossed dividend. Do not right shift when divisor is exactly equals to dividend.
7. We have to subtract the divisor from dividend and keep looping again(that will be only once)

*/

class Solution {
public:
  int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend; 
        if (dividend == numeric_limits<int>::min() && divisor == -1) return numeric_limits<int>::max(); 
        
        const auto sign_dividend = dividend < 0;
        const auto sign_divisor = divisor < 0;
        const auto sign = sign_dividend ^ sign_divisor;
        
        uint32_t u_dividend = sign_dividend ? ~(uint32_t)dividend + 1 : dividend;
        const uint32_t u_divisor = sign_divisor ? ~(uint32_t)divisor + 1 : divisor; 
        
        int quotient = 0;
        
        while (u_dividend >= u_divisor) {
            uint32_t subtract = u_divisor;
            uint32_t counter = 1;
            while (subtract < u_dividend) {
                subtract <<= 1;
                counter <<= 1;
            }
            quotient += subtract == u_dividend ? counter : counter >> 1;
            u_dividend -= subtract == u_dividend ? subtract : subtract >> 1;
        }
        
        return sign ? -quotient : quotient;
    }
};
