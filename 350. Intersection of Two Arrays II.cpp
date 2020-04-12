/**
Given two arrays, write a function to compute their intersection.
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

Approach:

Unordered_multiset - Stores all the elements including a list of duplicates. Every time we find an element in set, erase it.

**/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        if(nums1.size()==0 or nums2.size()==0)
            return ans;
        unordered_multiset<int> multi;
        for(int i : nums1)
            multi.insert(i);
        
        for(int i : nums2)
        {
            if(multi.find(i)!=multi.end())
            {
                ans.push_back(i);
                multi.erase(multi.find(i));
            }
        }
        return ans;
    }
};
