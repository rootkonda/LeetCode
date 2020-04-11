/**
   Given an array of integers, return indices of the two numbers such that they add up to a specific target.

   You may assume that each input would have exactly one solution, and you may not use the same element twice.

   Approach:
   
   For each element, check if it exists in the map. If it exists, return the appropriate indices. 
   Otherwise, subtract the element from target sum and store the compliment in map  **/

subtract each element from target sum and look if that target sum is present 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // To store the compliments
        unordered_map<int,int> unik;
        vector<int> res;
        res.push_back(-1); // default indices when no match
        res.push_back(-1); // default indices when no match
        for(int i=0;i<nums.size();i++)
        {
            if(unik.find(nums[i])!=unik.end())
            {
                res[0]=(unik[nums[i]]);
                res[1]=i;
                return res;
            }
            unik[target-nums[i]]=i; // stores the compliment
        }
        return res;
    }
};
