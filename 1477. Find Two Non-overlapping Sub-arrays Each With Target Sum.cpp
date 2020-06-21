/*
Given an array of integers arr and an integer target.

You have to find two non-overlapping sub-arrays of arr each with sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.

Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.


Sum maintains the running sum of a subarray which is equal to target.
left - start of the window
right - end of the window
best[left-1] always have smallest subarray, where sum equals to target.
Always keep updating the best[right] with smallest subarray length.
*/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) 
    {
        int right = 0;
        int left = 0;
        int sum=0;
        int ans = INT_MAX;
        vector<int> best(arr.size(),INT_MAX);
        int bestSoFar = INT_MAX;
        while(right<arr.size())
        {
            sum+=arr[right];
            while(sum>target)
            {
                sum-=arr[left];
                left++;
            }
            if(sum==target)
            {
                if(left>0 and best[left-1]!=INT_MAX)
                    ans = min(ans, best[left-1]+right-left+1);
                bestSoFar = min(bestSoFar,right-left+1);
            }
            best[right] = bestSoFar;
            right++;
        }
        return (ans==INT_MAX ? -1 : ans);
        
    }
};
