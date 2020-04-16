/**
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Sliding window approach
**/


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if(nums.size()==0)
            return 0;
        int start=0;
        int ans = INT_MAX;
        int sum = 0;
        int end =0;
        for(end=0;end<nums.size();end++)
        {
            sum+=nums[end];
            if(sum>=s)
            {
                while(sum>=s and start<=end)
                {
                    ans = min(ans,(end-start)+1);
                    sum-=nums[start];
                    start++;
                }
            }
        }
        if(ans!=INT_MAX)
            return ans;
        return 0;
    }
};
