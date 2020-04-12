/**

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Use a pointer starting from 0 and insert element everytime when its not zero.
**/

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int idx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
                nums[idx++]=nums[i];
        }
        for(int i=idx;i<nums.size();i++)
            nums[i]=0;
    }
};
