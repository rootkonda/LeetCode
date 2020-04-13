/**
Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence. 

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.

Just simple and straightforward.
**/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),greater<>());
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<int> ans;
        int currsum = 0;
        for(auto n : nums)
        {
            sum-=n;
            currsum+=n;
            ans.push_back(n);
            if(currsum>sum)
                break;
        }
        
        return ans;
    }
};
