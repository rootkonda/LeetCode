/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
  
Say we are trying to find diff(t)=4 for elements 1,3,9 when k is 3. 9-t(4) = 5 so it means we should find an element which is atleast 5 and max upto 9+t(4) 13.
If we use multiset then we maintain elements in sorted order at any point and also multiset size should not exceed k. Inorder to find "atleast and upto" we can use lower_bound of nums[i]-t. We use long long because if the input is INT_MAX and when we do nums[i]-t then it will cause overflow.

*/

typedef long long ll;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        if(t<0 or k<=0)
            return false;
        multiset<ll> dup;
        for(int i=0;i<nums.size();i++)
        {
            auto lb = dup.lower_bound(ll(nums[i])-t);
            if(lb!=dup.end() and *lb-nums[i]<=t)
                return true;
            dup.insert(nums[i]);
            if(dup.size()>k)
                dup.erase(nums[i-k]);
        }
        return false;
    }
};


/*
[1,2,3,1]
3
0
[1,0,1,1]
1
2
[1,5,9,1,5,9]
2
3
[-1,-1]
1
-1
*/
