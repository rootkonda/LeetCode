/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.


Check every possibility and form a string for every possibility and check if it is same as given string.
*/

class Solution {
public:
    bool isAdditiveNumber(string num) 
    {
        int n = num.size();
        for(int i=1;i<n;i++)
        {
            string a = num.substr(0,i);
            if(a.size()>1 and a[0]=='0') // Additive sequence cannot start with 0 so break if so
                break;
            
            for(int j=i+1;j<n;j++)
            {
                string b = num.substr(i,j-i);
                if(b.size()>1 and b[0]=='0')  // Additive sequence cannot start with 0 so break if so
                    break;
                long num1 = stol(a);
                long num2 = stol(b);
                long sum = num1+num2;
                string next = to_string(sum);
                string all = a+b+next;
                
                while(all.size()<n) // Forms the entire string based on the sum and two previous numbers.
                {
                    num1 = num2;
                    num2 = sum;
                    sum = num1+num2;
                    next = to_string(sum);
                    all.append(next);
                }
                if(all==num)
                    return true;
            }
        }
        return false;
    }
};
/*
"112358"
"199100199"
"0235813"
*/
