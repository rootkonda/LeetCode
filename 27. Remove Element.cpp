/**
  Given an array nums and a value val, remove all instances of that value in-place and return the new length.

  Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

  The order of elements can be changed. It doesn't matter what you leave beyond the new length.
  
  Approach:
  
  Same approach as problem 26. Keep a pointer at 0th index and increment when element at that index doesnt match with val. **/
  
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
       int len=nums.size();
       if(len==0)
           return 0;
       int idx=0;
       for(int i=0;i<len;i++)
       {
           if(nums[i]!=val)
               nums[idx++]=nums[i];
       }
       return idx;
    }
};
