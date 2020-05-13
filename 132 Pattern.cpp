/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

*/



class Solution {
public:
   
    bool find132pattern(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)
            return false;
        vector<int> minLeft(n);
        minLeft[0]=nums[0];
        for(int i=1;i<n;i++)
            minLeft[i] = min(minLeft[i-1],nums[i-1]); // At each position of nums keep track of the minimum.
        
        int minRightGreaterThanLeft = INT_MAX;
        int minRight;
        for(int i=n-2;i>0;i--)
        {
            minRight=min(minRightGreaterThanLeft,nums[i+1]); // We have to find the smallest element which is greater than left. And also always maintain the smaller element on the right i.e. nums[j] should be minimum always.
            if(minLeft[i]<minRight) // if minimum on the left nums[i] is lesser than nums[j]
                minRightGreaterThanLeft=minRight; // Update the nums[j] to the current nums[j]
            if(minLeft[i]<nums[i] and minLeft[i]<minRightGreaterThanLeft and nums[i]>minRightGreaterThanLeft) // This condition is to check nums[i]<nums[k]<nums[j]
                return true;
        }
        return false;
    }
};
