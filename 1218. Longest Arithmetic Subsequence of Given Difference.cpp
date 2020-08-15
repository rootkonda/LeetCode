/*

Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

Keep track of length of subsequence for each number in the given array in a map. Hence start from the back and also keep track of max length for each item.
*/


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) 
    {
        unordered_map<int,int> mp;
        int ans=1;
        for(int i=arr.size()-1;i>=0;i--)
        {
            mp[arr[i]] = 1+mp[arr[i]+diff];
            ans = max(ans,mp[arr[i]]);
        }
        return ans;
    }
};
