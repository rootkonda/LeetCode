/**
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Approach:

Idea is to find 3 distinct greater elements in the given input. Maintain them in descending order and for every element check the where it fits and move those values accordingly.

**/

class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        if(nums.size()==2)
        {
            if(nums[0]>nums[1])
                return nums[0];
            else
                return nums[1];
        }
        if(nums.size()==1)
            return nums[0];
        
        long long fmax=LLONG_MIN;
        long long smax=LLONG_MIN;
        long long tmax=LLONG_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(fmax<=nums[i])
            {
                if(fmax!=nums[i])
                {
                    tmax=smax;
                    smax=fmax;
                    fmax=nums[i];
                } 
            }
            else if(smax<=nums[i])
            {
                if(smax!=nums[i])
                {
                    tmax=smax;
                    smax=nums[i];
                } 
            }
            else if(tmax<=nums[i] and tmax!=nums[i])
            {
                tmax=nums[i];
            }
                
        }
        if(tmax!=LLONG_MIN)
            return tmax;
        return fmax;
    }
};
