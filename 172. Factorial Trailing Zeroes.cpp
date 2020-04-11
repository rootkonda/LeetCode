/**
  Given an integer n, return the number of trailing zeroes in n!.
  
  Simple. Just calculate the numberof 5's in the given 'n'.
  
**/
class Solution {
public:
    
    int trailingZeroes(int n) 
    {
        int count=0;
        while(n!=0)
        {
            count+=n/5;
            n/=5;
        }
        return count;
    }
};
