/**
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Same as subset problem except that we maintain a set to check if the new vector was already added to answer.
**/



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int len = nums.size();
        set<vector<int>> duplicates;
        vector<vector<int>> ans{{}};
        if(len == 0)
            return ans;
        for(int i=0;i<len;i++)
        {
            int sz = ans.size();
            for(int j=0;j<sz;j++)
            {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                sort(temp.begin(),temp.end());
                if(duplicates.find(temp)==duplicates.end())
                {
                    duplicates.insert(temp);
                    ans.push_back(temp);
                }
            }
        }
        return ans; 
    }
};
