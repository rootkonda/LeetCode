/*
Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal than target.

Since the answer may be too large, return it modulo 10^9 + 7.

Remember not to assume that subsequences doesnt mean continuous subsequences. In this case, we are talking about subsets hence order doesnt matter.

*/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
         int res = 0, mod = 1000000007;
         vector<int> pre = {0, 1}; // store the powers of 2, starting with the index 2
         for (auto i = pre.size(); i <= nums.size(); ++i)
             pre.push_back((pre.back() << 1) % mod);
         sort(begin(nums), end(nums)); // We are only looking for subsets not continuous subsequences.
         for (int i = 0, j = nums.size() - 1; i <= j; ++i) { // i from left and j from right
             while (i <= j && nums[i] + nums[j] > target) // j stays at the same pos then go to i+1 position and keep checking by decreasing j. This is why we sort so that we can be sure.
                 --j;
             res = (res + pre[j - i + 1]) % mod;
         }
         return res;
    }
};
