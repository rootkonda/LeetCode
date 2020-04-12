/**
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Number theory - This is equal to modulus 9 of given number.

**/
class Solution {
public:
    int addDigits(int num) 
    {
        if(num==0)
            return 0;
        int res=num%9;
        if(res==0)
            return 9;
        return res;
    }
};
