/**
Given an array nums of integers, return how many of them contain an even number of digits.

Just look for the ranges and keep count.
**/

class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int count=0;
        for(auto x:nums)
        {
            if(x>=10 and x<=99)
                count++;
            else if(x>=1000 and x<=9999)
                count++;
            else if(x>=100000)
                count++;
        }
        return count;
    }
};
