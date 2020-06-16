/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Dutch National Flag Problem.

We just have to maintain two pointers, one from the front and another is from the back. Take 1 as our pivot and push 0(lesser) elements to the left of 1
and 2(greater than 1) to the right. Whenever we find elements greater than 1, then swap it with elements from the back and just stay at current position.
*/


class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int i=0,j=0;
        int n = nums.size();
        while(j<n)
        {
            if(nums[j]<1)
                swap(nums[i++],nums[j++]);
            else if(nums[j]>1)
                swap(nums[j],nums[--n]);
            else
                j++;
        }
    }
};


/*
[2,0,2,1,1,0]
[2,0,2,1,1,0]
*/
