/**
  Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
  
  Approach:
  
  Kadane's Algorithm - Start from 2nd element. For each iteration, compare sum of current+previous elements and current element,
  whichever is maximum that will be the new sum.
  
  **/
  
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int len=nums.size();
        int sum=nums[0],mx=sum;
        for(int i=1;i<len;i++)
        {
            sum=max(nums[i],nums[i]+sum);
            if(sum>mx)
                mx=sum;
        }
        return mx;
    }
};
