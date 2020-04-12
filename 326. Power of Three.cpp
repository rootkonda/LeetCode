/**
Given an integer, write a function to determine if it is a power of three.
Follow up:
Could you do it without using any loop / recursion?

Using log2(n)/log2(exp). 
**/

class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(n<=0)
            return 0;
        int exp = (log2(n)/log2(3));
        return n==pow(3,exp);
    }
};
