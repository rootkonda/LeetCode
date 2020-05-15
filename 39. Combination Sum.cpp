/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

https://leetcode.com/problems/combination-sum/discuss/623346/C%2B%2B-2-solution-or-Backtracking-and-DP-(Unbounded-knapsack)

*/

class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, vector<int> curr, int start,int target)
    {
        if(target==0) // When target is 0 then it means this is the proper solution set
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i=start;i<candidates.size() and candidates[i]<=target;i++) // Choose a candidate only if it is less than or equal to the remaining target.
        {
            curr.push_back(candidates[i]);
            helper(candidates,curr,i,target-candidates[i]); // Loop thru with the same index until this element reaches the target or greater than it.
            curr.pop_back(); // Remove this element and check with next
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end()); // We have to sort it in order to avoid unnecessary recursions.
        helper(candidates,{},0,target);
        return ans;
        
    }
};
