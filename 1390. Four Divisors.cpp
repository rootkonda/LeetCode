/*
Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

If there is no such integer in the array, return 0.

*/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) 
    {
        int ans = 0;
        for(auto num : nums)
        {
            int count=0;
            int sum=0;
            for(int i=1;i*i<=num;i++) // This condition is important when we try to find the divisors as sqrt(n)<=num like we do in segment sieves. 
            {
                if(num%i==0)
                {
                    if(num/i==i) // This condition is to avoid double counting of same divisors.
                    {
                        sum+=i;
                        count++;
                    }
                    else
                    {
                        sum+=i+(num/i);
                        count+=2;
                    }
                }
            }
            if(count==4)
                ans+=sum;
        }
        return ans;
    }
};
