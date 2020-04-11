/**

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Simple and straightforward. Keep track of the duplicate count and check if passes the condition every iteration.
**/

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int len=nums.size();
        int lim=len/2;
        unordered_map<int,int> count;
        for(int i=0;i<len;i++)
        {
            count[nums[i]]++;
            if(count[nums[i]]>lim)
                return nums[i];
        }
        return 0;
    }
};
