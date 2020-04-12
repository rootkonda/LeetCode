/**
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

Approach:
1. Convert each character to int using c - '0';
2. Add them, maintain carry and add unit digit of sum to result.
3. Process the leftovers at the end.

**/

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int carry=0,t,a,b;
        string res="";
        int i=num1.length()-1,j=num2.length()-1;
        while(i>-1 and j>-1)
        {
            a=num1[i]-'0';
            b=num2[j]-'0';
            t=(a+b);
            if(carry)
                t+=carry;
            carry=t/10;
            res=to_string(t%10)+res;
            i--;
            j--;
        }
        while(i>-1)
        {
           a=num1[i]-'0';
           t=a;
           if(carry)
              t=a+carry;
           carry=t/10;
           res=to_string(t%10)+res;
           i--;
        }
        while(j>-1)
        {
           b=num2[j]-'0';
           t=b;
           if(carry)
               t=b+carry;
           carry=t/10;
           res=to_string(t%10)+res;
           j--;
        }
        if(carry)
            res=to_string(carry)+res;
        return res;
    }
};
