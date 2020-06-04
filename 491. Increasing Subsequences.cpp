/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.
Note:

The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

*/

class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> dup;
    void sub(vector<int>& nums,vector<int> curr,int index)
    {
        if(curr.size()>=2)
        {
            if(dup.insert(curr).second)
                ans.push_back(curr);
        }
        
        for(int i=index;i<nums.size();i++)
        {
            if(curr.size()>0 and curr.back()<=nums[i])
                continue;
            curr.push_back(nums[i]);
            sub(nums,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        sub(nums,vector<int>(),0);
        return ans;
    }
};

/*
[1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]
[6,4,7,7]
[4,6,7,7]
[6,2,1,9]
*/
