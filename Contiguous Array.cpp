/**
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Equal number of 0's and 1's means try to make a sum of 0. i.e. set all 0's to -1 and calculate the prefix sum upto the current element. Check every time whether the sum already in map, if it exists, then take the difference between the index of that and current index.

**/
// 0 0 1 1
// -1 -1 1 1

class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int ans = 0;
        int count = 0;
        unordered_map<int,int> first;
        first[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            count+=(nums[i]==0 ? -1 : 1);
            if(first.find(count)!=first.end())
                ans = max(ans,i+1-first[count]);
            else
                first[count]=i+1;
        }
        return ans;
    }
};
