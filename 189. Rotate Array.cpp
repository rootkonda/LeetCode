/**

Given an array, rotate the array to the right by k steps, where k is non-negative.

If k is larger than nums.size() then do mod of len to get the appropriate number of shifts. It is a cycle so everytime we pass the 
length of the array, decrement the k. When k reaches 0, then it means all elements are rotated. Calculate npos and keep the
temporary element for next iteration.
**/

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int cpos=0,npos=-1;
        int temp=nums[0],prev;
        int len=nums.size();
        int start=0,offset;
        k%=len;
        offset=k;
        while(k)
        {
            if(start==npos)
            {
                cpos++;
                start=cpos;
                temp=nums[cpos];
            }
            if(cpos+offset>=len)
            {
                npos=(cpos+offset)%(len);
                prev=nums[npos];
                nums[npos]=temp;
                temp=prev;
                cpos=npos;
                k--;
            }
            else
            {
                npos=cpos+offset;
                prev=nums[npos];
                nums[npos]=temp;
                temp=prev;
                cpos=npos;
            }
        }
    }
};
