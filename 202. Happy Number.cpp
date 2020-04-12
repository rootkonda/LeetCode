/**

Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Reference: https://www.johndcook.com/blog/2018/03/24/squared-digit-sum/

Take any positive integer n and sum the squares of its digits. If you repeat this operation, eventually you’ll either end at 1 or cycle between the eight values 4, 16, 37, 58, 89, 145, 42, and 20.

**/

class Solution 
{
public:
    bool isHappy(int n) 
    {
        int count=0;
        int total=0;
        while(true)
        {
            while (n)
            {
                total+=pow((n%10),2);
                n/=10;
            }
            if(total==1)
                return true;
            else if(count==8)
                return false;
            n=total;
            total=0;
            count++;
        }
              
    }
};
