/*
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

We have to try adding each stick length to every side of the square and see if it forms a square. If all sides are equal then return true or false; Use backtracking algorithm here....Add each stick length to each side and recurse with next stick length and whenever it crosses the target side, we should subtract the element again and try adding it to different side.


class Solution {
public:
    int sums[4];
    int n;
    bool helper(int index,vector<int>& nums,int target)
    {
        if(index==n)
            return (sums[0]==sums[1] and sums[1]==sums[2] and sums[2]==sums[3]);
        
        int element = nums[index];
        for(int i=0;i<4;i++)
        {
            if(sums[i]+element<=target)
            {
                sums[i]+=element;
                if(helper(index+1,nums,target))
                    return true;
                sums[i]-=element;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& nums) 
    {
        long long perimeter = accumulate(nums.begin(),nums.end(),0);
        long long sum = 0;
        n = nums.size();
        if(n<4)
            return false;
        memset(sums,0,sizeof(sums));
        int i=0,j=1;
        if(perimeter & 3) // checks if it is a multiple of 4. Since it is power of 2, we can use &3 for modulo operation.
            return false;
        long side = perimeter>>2;
        sort(nums.rbegin(),nums.rend()); // Descending order to make it faster.
        return helper(0,nums,side);
        
    }
};
