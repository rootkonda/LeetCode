/**
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Simple. Implement using map and check difference <=k when there is a duplicate.
**/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(nums.size()==0 or k==0)
            return false;
        unordered_map<int,int> diff;
        for(int i=0;i<nums.size();i++)
        {
            if(diff.find(nums[i])==diff.end())
                diff[nums[i]]=i;
            else if(abs(diff[nums[i]]-i)<=k)
                return true;
            else
                diff[nums[i]]=i;
        }
        return false;
    }
};
