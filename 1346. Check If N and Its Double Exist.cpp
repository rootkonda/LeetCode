/**
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

Similar to Two sum approach.

**/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_set<int> nums;
        int count=0;
        for(auto i : arr)
        {
            if(!nums.insert(i).second)
                return true;
            if(!nums.insert(i*2).second)
                return true;
        }
        return false;
    }
};
