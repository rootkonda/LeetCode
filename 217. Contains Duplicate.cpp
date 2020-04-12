/**
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Simple. Just use to map to keep track of duplicates.
**/

class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
                return true;
            else
                mp[nums[i]]=i;
        }
        return false;
    }
};
