/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Whenever we get a remainder by doing num%den, then keep getting the quotient until the remainder becomes zero or if the same remainder appears again. If same remainder appears again then it means the sequence is going to repeat again. Hence we have keep track of how many characters in the fractional part should be considered and rest is the repeating part. 
*/

class Solution {
public:
    string fractionToDecimal(long num, long den, string frac="",int count=1) 
    {
        const auto sign = (num<0) ^ (den<0);
        num = abs(num),den=abs(den);
        long rem = num%den;
        unordered_map<int,int> vis{{(int)rem,0}};
        string ans = (sign ? "-"+to_string(num/den) : to_string(num/den));
        while(rem)
        {
            rem*=10;
            frac.append(to_string(rem/den));
            rem%=den;
            if(vis.count(rem))
                return ans + "."+ frac.substr(0,vis[rem]) + "("+frac.substr(vis[rem])+")";
            
            vis.insert({rem,count++});
        }
        return num==0 ? "0" : (frac.empty() ? ans : ans+"."+frac);
    }
};
