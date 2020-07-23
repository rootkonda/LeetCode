/*

You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.

https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/discuss/419639/Python3-4-liner-w-explanation
https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/discuss/422558/Javascript-and-C%2B%2B-solutions

Firstly count number of x,y and y,x pairs. If there is a left over odd number of pairs then we cannot make them equal so 
(a+b)%2 - odd means u cannot make them equal so -1
(a/2) - Matching pairs of x,y
(b/2) - Matching pairs of y,x
(a%2) and (b%2) remainders leftovers of a and b pairs.

*/
class Solution {
public:
    int minimumSwap(string A, string B,int a=0,int b=0) 
    {
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=B[i])
            {
                a+=A[i]=='x';
                b+=B[i]=='x';
            }  
        }   
        return (a+b)%2 ? -1 : (a/2)+(b/2)+(a%2)+(b%2);
    }
};
