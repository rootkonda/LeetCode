/*
Given a binary string s (a string consisting only of '0' and '1's).

Return the number of substrings with all characters 1's.

Since the answer may be too large, return it modulo 10^9 + 7.

Find out the length of substring which contains only 1's and then use n*(n+1)/2 formula to find out number of substrings that can be formed for a given length and then add it to the answer. Using long and MOD avoids overflow.

*/

#define MOD 1000000007
class Solution {
public:
    int numSub(string s) 
    {
        long ans=0;
        int i=0;
        while(i<s.size())
        {
            long n=0;
            while(i<s.size() and s[i]=='1')
            {
                n++;
                i++;
            }
            i++;
            if(n)
               ans = (ans+n*(n+1)/2)%MOD;     
        }
        return ans;
    }
};
