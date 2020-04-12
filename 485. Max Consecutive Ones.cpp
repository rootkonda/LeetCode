/**
Given a binary array, find the maximum number of consecutive 1s in this array.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

Simple. Just check for consecutive ones and count everytime and maintian the max.
**/
class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ones=0;
        int count=1;
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]==1)
            {
                while(i+1<nums.size() and nums[i]==nums[i+1])
                {
                    count++;
                    ones=max(ones,count);
                    i++;
                }
                if(ones==0)
                    ones=1;
            }
            i++;
            count=1;
        }
        return ones;  
    }
};
