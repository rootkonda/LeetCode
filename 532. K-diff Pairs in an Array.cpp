/**
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Approach - To check the map if the num exists already. If exists then there is a pair, if it doesnt exist, then check if its compliment exists and count its occurences and add that to the answer.
**/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        int ans = 0;
        if(k < 0) 
            return 0;
        for(int num:nums)
        {
            if(k == 0 && mp[num] == 1)
            {
                ans++;
            }
            else if(k > 0 && mp[num] == 0)
            {
                ans += mp.count(num - k) + mp.count(num + k);
            }
            mp[num]++;
        }
        return ans;
    }
};
