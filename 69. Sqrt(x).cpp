/** 
  Implement int sqrt(int x).

  Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

  Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
  
  Approach:
  
  Binary search. low as 1 and high as x and compare the sqr of mid to x and whenever sqr<x keep track of mid and later return mid.**/
  **/
class Solution {
public:
    int mySqrt(int x) 
    {
        if(x==0 or x==1)
            return x;
        long low=1,high=x;
        long res;
        while(low<=high)
        {
            long mid=(low+high)>>1;
            long sqr=mid*mid;
            if(sqr == x)
                return mid;
            if(sqr < x)
            {
                low=mid+1;
                res=mid;
            }
            else
                high=mid-1;
        }
        return res;
    }
};
