/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into sets of k consecutive numbers
Return True if its possible otherwise return False.

*/


class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        int n = (int)nums.size();
        if(n%k) // In order to divide given nums into k equal sets, the size should be divisible by k
            return false;
        
        map<int,int> count; // Use map to sort the given numbers with their counts
        for(auto num: nums)
            count[num]++;
        
        int t = n/k; // t has number of sets to be formed
        while(t--)
        {
            int items = 0;
            int prev = 0;
            for(auto itr : count)
            {
                if(items==k) // A set is formed so break
                    break;
                if(itr.second>0 and (prev==0 or itr.first-prev==1)) // check with previous element to make sure its consecutive
                {
                    prev = itr.first; // keep track of previous element
                    items++; // count elements in the set
                    count[itr.first]--; // after using an element reduce its count so that we wont pick up twice
                }
            }
            if(items!=k)
                return false;
        }
        return true;
    }
};
