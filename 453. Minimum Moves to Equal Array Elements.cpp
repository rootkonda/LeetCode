/**
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

1. Find the smallest element.
2. Sum the difference between the smallest element and all elements
**/

class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int len=nums.size();
        if(len==1)
            return 0;
        
        vector<int> ans(len-1);
        int mx=nums[0],mn=nums[0];
        
        for(int i=1;i<len;i++)
        {
            if(mn>nums[i])
                mn=nums[i];
        }
        int sum=0;
    
        for(int i=0;i<len;i++)
            sum+=(nums[i]-mn);
        
        return sum;
    }
};

// 1,2,3,8
// 7,6,5
// 7+1+2=10

// 1, 2, 3, 9
// 8, 7, 6
// 8 + 1 + 2 =11

// 1 2 3
// 2,1
// 2+1 =3

// 1 2 3 5
// 4,3,2
// 4+ 1+2=7
