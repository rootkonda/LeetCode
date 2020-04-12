/**
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.

We have to check for divisors upto sqrt of given num. Make sure not to double count.
**/

class Solution 
{
public:
    bool checkPerfectNumber(int num) 
    {
        vector<int> ans;
        if(num<=0)
            return false;
        int lim=sqrt(num);
        for(int i=1;i<=lim;i++)
        {
            if(num%i==0 and num!=i)
            {
                int div=num/i;
                if(div!=i and div!=num) // Not to double count and divisor should not be given num
                {
                    ans.push_back(div);
                    ans.push_back(i);
                }
                else
                    ans.push_back(i);
            }
        }
        int sum=accumulate(ans.begin(),ans.end(),0);
        if(sum==num)
            return true;
        return false;
    }
};
