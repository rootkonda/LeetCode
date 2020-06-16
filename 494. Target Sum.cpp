/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

*/
class Solution {
public:
     int ans=0;
     vector<pair<int,int>> dp;
     void cal(vector<int>& nums, int S, int total, int index)
     {
         int sum=0;
         if(index==nums.size())
         {
             if(S==total)
                 ans++;
             return;
         }
         cal(nums,S,total+nums[index],index+1);
         cal(nums,S,total-nums[index],index+1);
     }
    int findTargetSumWays(vector<int>& nums, int S)
    {
        cal(nums,S,0,0);
        return ans;
    }
};
