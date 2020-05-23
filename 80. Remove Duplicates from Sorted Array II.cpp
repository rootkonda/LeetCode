/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/


 class Solution {
 public:
     int removeDuplicates(vector<int>& nums)
     {
         int n = (int)nums.size();
         int j = 1;
         int i;
         int count = 1;
         int index = -1;
         while(j<n)
         {
             if(count==2)
                 index = j;
             if(nums[j-1]==nums[j])
                 count++;
             else
             {
                 while(count>2)
                 {
                     nums[index++] = INT_MAX;
                     count--;
                 }
                count=1;
             }
             j++;
         }
         while(count>2)
         {
             nums[index++] = INT_MAX;
             count--;
         }
         for(i=0;i<n;i++)
         {
             if(nums[i]==INT_MAX)
             {
                 index=i+1;
                 while(index<n)
                 {
                     if(nums[index]!=INT_MAX)
                     {
                         swap(nums[i],nums[index]);
                         break;
                     }
                     index++;
                 }
                 if(index==n)
                     break;
             }
         }
         return i;
     }
 };

/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return n;
        int i=0;
        int tail=-1;  
        int r=0;
        while(i<n){
            int j=i;
            i++;
            while(i<n&&(nums[i]==nums[i-1]))
                i++;
            int d = i-j;
            for(int k=0;k<min(d,2);k++){
                nums[++tail]=nums[j];   
                r++;
            }
        }
        return r;
    }
};
*/
