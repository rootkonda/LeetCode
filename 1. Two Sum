class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // 
        unordered_map<int,int> unik;
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        for(int i=0;i<nums.size();i++)
        {
            if(unik.find(nums[i])!=unik.end())
            {
                res[0]=(unik[nums[i]]);
                res[1]=i;
                return res;
            }
            unik[target-nums[i]]=i;
        }
        return res;
    }
};
