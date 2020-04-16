/**
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

Difference between prefix sums should be K
1. First calculate the prefix sums
2. Start with a map of 0,0
3. Loop thru prefix sums and for each prefix sum, check if it exists in the map and add its count to answer if it exists.
4. As we are looking for difference between prefix sums, means prefix sum + K should be a prefix sum (if it exists) so add this to map and increment its count everytime we find it.

**/

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int ans = 0;
        vector<int> pref;
        unordered_map<int,int> sums;
        pref.push_back(0);
        for(int i=0;i<nums.size();i++)
            pref.push_back(nums[i]+pref.back());
        
        sums.insert({0,0});
        for(int i=0;i<pref.size();i++)
        {
            if(sums.find(pref[i])!=sums.end())
                ans+=sums[pref[i]];
            sums[pref[i]+k]++;
        }
        return ans;   
    }
};
