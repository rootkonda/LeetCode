/**
Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Prefix sum technique is used by replacing even numbers with 0's and odd numbers with 1's so k odd numbers become sum of 1's.
**/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans = 0;
        unordered_map<int,int> sums;
        sums.insert({0+k,1});
        int pref = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
                pref+=1;
            if(sums.find(pref)!=sums.end())
                ans+=sums[pref];
            sums[pref+k]++;
        }
        return ans;
            
    }
};
