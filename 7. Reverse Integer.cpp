/**
  Given a 32-bit signed integer, reverse digits of an integer.
  
  Simple approach. Initialize res to unit digit and truncate x by last digit. 
  Run a loop until x becomes 0 or no more digits to reverse. Every time multiple by 10 and add the next digit. **/
class Solution 
{
public:
    int reverse(int x) 
    {
        long res=(x%10);
        x/=10;
        while(x!=0)
        {
            if(abs(res*10) > 2147483640)
                return 0;
            else
            {
                res=res*10;
                res+=(x%10);
                x/=10;
            }  
        }
        return res;
    }
};
