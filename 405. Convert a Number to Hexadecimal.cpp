/**
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.

Approach:
Get the remainder of n mod 16 and if it is >9 add it with 'W' to get the alphabet.

**/

class Solution {
public:
    string toHex(int num) 
    {
        unsigned int n=num;
        if(n==0)
            return "0";
        string ans="";
        char c='W';
        while(n!=0)
        {
            int r = n%16;
            if(r>9)
            {
                char t = (char)(c+r);
                ans = t + ans;
            }
            else
                ans = to_string(r) + ans;
            n/=16;
        }
        return ans;
    }
};
