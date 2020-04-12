/**
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Dynamic Programming: In the dp array, we always store the maxProfit till each house and use that for next calculation.
1. At house zero, the max profit is 0.
2. At house one, the max profit is 1.
3. At house two, the max profit is max(house-1, house-0+house-2)

This repeats until no more houses. The last element in the dp array is the answer.

**/


class Solution 
{
public:
    int rob(vector<int>& nums)
    {
        int len=nums.size();
        if(len==0)
            return 0;
        else if(len==1)
            return nums[0];
        else if(len==2)
            return max(nums[0],nums[1]);
            
        vector<int> dp(len);
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<len;i++)
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        return dp[len-1];
    }
};
