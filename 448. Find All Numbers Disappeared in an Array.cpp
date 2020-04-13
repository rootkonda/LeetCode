/**

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Approach - Since the given numbers are in the range of 1 to n. Treat each number as index and make it -ve. The +ve numbers are the numbers which are missing. You can also solve many other problems when given range is 1 to n.
**/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> ans;
        int idx=0,next=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                idx=-nums[i]-1;
            else
                idx=nums[i]-1;
            if(nums[idx]>0)
                nums[idx]=-nums[idx];
        }
            
        for(int j=0;j<nums.size();j++)
            if(nums[j]>0)
                ans.push_back(j+1);
        
        return ans;
    }
};
