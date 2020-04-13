/**
Given a non-negative integer num, return the number of steps to reduce it to zero. If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

Simple.
**/

class Solution 
{
public:
    int numberOfSteps (int num) 
    {
        if(num==0)
            return 0;
        int p = (int)log2(num);
        int v=(int)pow(2, p);
        if(v==num) 
            return p+1;
        else
        {
            int t,count=0;
            while(true)
            {
                if(num==0)
                    return count;
                t=num%2;
                if(t==0)
                    num/=2;
                else
                    num-=1;
                count++;
            }
        }
    }
};
