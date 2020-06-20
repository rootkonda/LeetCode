/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Keep dividing n by 2 and for every odd number multiply the result with ans.
*/

class Solution {
public:
    double myPow(double x, int n) 
    {
        double ans=1.0;
        for(int i=n;i;i/=2)
        {
            if(i&1)
                ans*=x;
            x*=x;
        }
        
        return (n<0 ? 1.0/ans : ans);
    }
};
