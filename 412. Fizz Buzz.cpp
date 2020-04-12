/**
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Simple and straightfoward.
**/

class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> ans(n);
        int idx=0;
        for(int i=1;i<=n;i++)
        {
            if(i%3==0)
            {
                 ans[idx]="Fizz";
                 if(i%5==0)
                    ans[idx]+="Buzz";
                 idx++;
            }
            else if(i%5==0)
                ans[idx++]="Buzz";
            else
                ans[idx++]=to_string(i);
        }
        return ans;
    }
};
