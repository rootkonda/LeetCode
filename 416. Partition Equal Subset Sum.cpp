/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.

Explanation
-----------
We have to sort the given numbers in ascending order because we can the duplicate elements when trying to find a subset which is equal to targetSum.
Say initially we keep taking all the elements from the sorted array and we see that it exceeds the targetSum then it means we should try taking the next element in the subset and we should'nt take the same element because the new sum is may be equal to targetSum but since we should split it into two subsets of equal sum it won't be possible with smaller elements.

*/




class Solution {
public:
    bool isPossible(vector<int>& nums,int targetSum,int index,int currSum)
    {
        if(currSum==targetSum)
            return true;
        if(currSum>targetSum)
            return false;
        for(int i=index;i<nums.size();i++)
        {
            currSum+=nums[i];
            if(i==index or nums[i]!=nums[i-1])
            {
                if(isPossible(nums,targetSum,i+1,currSum))
                    return true;
            }
             currSum-=nums[i];
        }
        return false;
    }
    bool canPartition(vector<int>& nums) 
    {
        int total = accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end());
        if(total%2!=0)
            return false;
        return isPossible(nums,total/2,0,0);
    }
};

