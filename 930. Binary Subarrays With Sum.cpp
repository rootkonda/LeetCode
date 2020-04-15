/**
In an array A of 0s and 1s, how many non-empty subarrays have sum S?

1. Prefix sum technique is used.
2. For each element, calculate prefix sum upto that element.
3. Check if that sum already exists in the map and add that count of occurences to answer.
4. If it does not exists, add prefix sum + S(given sum) - means we are going to look for this prefix sum. When it comes, we add the number of occurences to the answer.

**/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S)
    {
        
        int N = A.size();
        int sum = 0;
        unordered_map<int,int> count;
        count.insert({S,1});
        int ans = 0;
        for (int x: A) 
        {
            sum+=x;
            ans += count[sum];
            count[sum+S]++;
        }
        return ans;
    }
};
