/**

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Simple. difference between n(n+1)/2 formula and the sum of given numbers.
**/

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int target = (n * (n+1))>>1;
        return target-sum;
    }
};

// (10 * 11)/2 = 55
// (9 * 10)/2 = 45

//1,2,3,4,5,6,7,9 = 37
//0,1,2,3,4,5,6,7,8,9 = 45
