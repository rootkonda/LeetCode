/**
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Approach:

Use a temporoary list and two pointers for two lists. At the end assign the temp list to nums1.
**/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int> temp;
        int i=0,j=0;
        while(i<m and j<n)
        {
            if(nums1[i]<nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i!=m)
            temp.push_back(nums1[i++]);
        while(j!=n)
            temp.push_back(nums2[j++]);
        
        nums1=temp;
    }
};
