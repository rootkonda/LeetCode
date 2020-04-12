/**
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.

Simple. Prepare list of pairs and sort it. Assign the ranks.
**/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) 
    {
        vector<pair<int,int>> ranks;
        vector<string> ans(nums.size());
        for(int i=0;i<nums.size();i++)
            ranks.push_back(make_pair(nums[i],i));
        
        sort(ranks.begin(),ranks.end(),greater<>());
        int i=0;
        for(i=3;i<nums.size();i++)
            ans[ranks[i].second]=to_string(i+1);
        
        if(nums.size()>=3)
        {
            ans[ranks[2].second] = "Bronze Medal";
            ans[ranks[1].second] = "Silver Medal";
            ans[ranks[0].second] = "Gold Medal";
        }
        else if(nums.size()==2)
        {
            ans[ranks[1].second] = "Silver Medal";
            ans[ranks[0].second] = "Gold Medal";
        }
        else
            ans[ranks[0].second] = "Gold Medal";
            
        return ans;
    }
};
