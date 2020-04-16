/**
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Reference: https://www.youtube.com/watch?v=HbIA1z1ySvo

For each element:
1. Find maxProduct till that element inclusive.
2. Find minProduct till that element inclusive.
3. If the element is -ve then swap the maxProduct and minProduct values.
For example:
4 -2 1 -2 = Final answer(16)
ans = 4;
1. maxProduct = 4
   minProduct = 4
   ans = max(ans,maxProduct) = 4
   
2. -2<0
    swap (maxProduct,minProduct)
    maxProduct = max(4*-2,-2) = -2 [-2]// Kadane's algorithm
    minProduct = min(4*-2,-2) = -8 [4,-2] 
    ans = max(ans,maxProduct) = 4

3. maxProduct = max(-2*1,1) = 1 [1]
   minProduct = min(-8*1,1) = -8 [4,-2,1]
   ans = 4;

4. -2<0
   swap(maxProduct,minProduct)
   maxProduct = max(-8*-2,-2) = 16 [4 -2 -1 -2]
   minProduct = min(1*-2,-2) = -2 [-2]
   ans = 16;
**/

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = nums[0];
        int maxproduct = 1, minproduct = 1;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(maxproduct,minproduct);
            maxproduct = max(maxproduct*nums[i],nums[i]);
            minproduct = min(minproduct*nums[i],nums[i]);
            ans = max(ans,maxproduct);
        }
        return ans;
    }
};
