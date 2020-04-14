/**
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.

Approach:

Look for a cycle of mod k. If there is a cycle exists, then subarray of sum k exists. 
**/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> visited;
        visited.insert({0,-1});
        int curr = 0;
        for(int i=0;i<nums.size();i++)
        {
            curr = k ? (curr+nums[i])%k : curr+nums[i];
            visited.insert({curr,i});
            if(i - visited[curr] > 1)
                return true;
        }
        return false;
    }
};

//23,7,6,4,2
