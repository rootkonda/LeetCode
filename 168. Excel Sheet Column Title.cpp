/**

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

Repeat modulus of 26 on the given number until it becomes zero. Each time, check if reminder is zero then decrement n by 1.
Insert the letter at the beginning of string.

**/

class Solution {
public:
    string convertToTitle(int n) 
    {
        char c=64;
        string output;
        int mod,div;
        while(n!=0)
        {
            mod=n%26;
            if(mod==0)
            {
                n--;
                string s(1,c+26);
                output.insert(0,s);
            }
            else
            {
                string s(1,c+mod);
                output.insert(0,s);
            }
            n/=26;
        }
        return output;
    }
};
