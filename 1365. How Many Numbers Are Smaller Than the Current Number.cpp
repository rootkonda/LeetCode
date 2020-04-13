/**
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

Just store the elements in a pair of vectors and then sort them and use index to know count of elements before that.
**/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
        vector<pair<int,int>> pos;
        int len=nums.size();
        for(int i=0;i<len;i++)
            pos.push_back(make_pair(nums[i],i));
        sort(pos.begin(),pos.end());
        vector<int> res(len);
        
        for(int i=0;i<len;i++)
        {
            if(i==0)
                res[pos[i].second]=i;
            else if(pos[i].first==pos[i-1].first)
                res[pos[i].second]=res[pos[i-1].second];
            else
                res[pos[i].second]=i;
        }
        return res;
    }
};
