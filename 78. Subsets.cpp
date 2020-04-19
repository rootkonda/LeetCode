/**
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.


Add empty element into vector at the beginning.
Next, start from the first element in the array and loop thru the answer array and keep appeding the new element to every vector in the answer array and add that new vector into the answer again.

So what happens here is, number of elements in answer vector will change in the order of 2^N.
After 1st element, size of answer becomes 2
After 2nd element, size of answer becomes 4
After 3rd element, size of answer becomes 8
and so on....
**/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i = 0;i<n;i++)
        {
            int temp = nums[i];
            int sz = ans.size();
            for(int i=0;i<sz;i++)
            {
                vector<int> r = ans[i];
                r.push_back(temp);
                ans.push_back(r);
            }
        }
        return ans;
    }
};
