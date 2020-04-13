/**
Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.

The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them. 

Simple.
**/

class Solution {
public:
    string generateTheString(int n) {
        char c[]={'a','b','c','d','e','f','g'};
        string res="";
        if(n%2!=0)
        {
            for(int i=0;i<n;i++)
            {
                res+=c[0];
            }
        }  
        else
        {
            for(int i=0;i<n-1;i++)
                res+=c[0];
            res+=c[1];
        }
        return res;
        
    }
};
