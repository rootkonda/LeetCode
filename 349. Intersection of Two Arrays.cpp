/**
Given two arrays, write a function to compute their intersection.

Note:

Each element in the result must be unique.
The result can be in any order.

Approach:

This is about finding common elements in both arrays.
1. Sort both arrays, linear loop on first array and for each iteration use binary search. Like below.
2. Use map or set to store the values of first array and loop thru the second array to see if that element exists.
**/



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
             vector<int> ans;
             if(nums1.size()==0 or nums2.size()==0)
                 return ans;
             sort(nums1.begin(),nums1.end());
             sort(nums2.begin(),nums2.end());
             int low;
             int high;
             int mid,target=nums1[0]-1;
             
              for(int i=0;i<nums1.size();i++)
              {
                  if(target!=nums1[i])
                  {
                      target=nums1[i];
                      low=0;
                      high=nums2.size()-1;
                      while(low<=high)
                      {
                         mid=low+(high-low)/2;
                         if(nums2[mid]==target)
                         {
                             ans.push_back(nums2[mid]);
                             break;
                         }
                         else if(nums2[mid]>target)
                         {
                             high=mid-1;
                         }
                         else
                             low=mid+1;
                      } 
                  }   
              }
      return ans;
      }
};
