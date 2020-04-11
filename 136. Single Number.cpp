/**
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

XOR every number and that gives a result of unique number.
**/

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans=0;
        for(int k=0;k<nums.size();k++)
            ans^=nums[k];
        return ans;    
    }
};
