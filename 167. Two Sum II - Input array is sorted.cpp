/**
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Same as 1.Two Sum problem. Either store the compliment and look for number or vice versa.

**/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<numbers.size();i++)
        {
            int comp=target-numbers[i];
            if(mp.find(comp)!=mp.end())
            {
                ans.push_back(mp[comp]+1);
                ans.push_back(i+1);
                return ans;
            }
            mp[numbers[i]]=i;
        }
        return ans;
    }
};
