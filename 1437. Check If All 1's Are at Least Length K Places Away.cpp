/*
Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.

Except for the first time, left will always stay on last seen 1 and keep moving right to find next 1. Once we find the next 1 then we update the left to point to the new 1 and increment the right
*/
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        int left=0,right=0;
        while(left<nums.size() and right<nums.size())
        {
            if(nums[left]) 
            {
                right = left+1;
                int cnt=0;
                while(right<nums.size() and !nums[right])
                    cnt++,right++;
                if(cnt<k and right<nums.size())
                    return false;
                left = right++;
            }
            else
                left++;
        }
        return true;
    }
};
