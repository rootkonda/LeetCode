/*

For each element - keep track of direction of movement, starting index and last moved direction. This is useful to check whether cycle exists.
Keep track of visited index and if visited again then check for cycle and break.
*/


class Solution {
public:
    bool circularArrayLoop(vector<int>& nums)
    {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,0);
            int len = 0;
            int curr = (nums[i]>0 ? 1 : -1);
            int next = curr;
            int index = i;
            while(true)
            {
                if(vis[index] or next!=curr)
                {
                    if(len>1 and next==curr and i==index)
                        return true;
                    break;
                }
                vis[index]=1;
                len++;
                if(nums[index]<0)
                {
                    next = -1;
                    if(index+nums[index]<0)
                    {
                        index = index+nums[index]%n;
                        index = (index<0 ? index+n : index);   
                    }
                    else
                        index = index+nums[index];
                }
                else
                {
                    index = (index+nums[index])%n;
                    next = 1;
                }
                    
            }
        }
        return false;
    }
};
/*
[-1,2]
[2,-1,1,2,2]
[-2,1,-1,-2,-2]
[-1,-2,-3,-4,-5]
[-1,-1,-3]
[-2,-17,-1,-2,-2]
*/
