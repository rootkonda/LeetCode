/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Key point here is if we want 3 values in sorted order then we keep track of minimum from left and maximum from the right and the middle element. So for each element in given array, we keep minimum element in c1 and minium element in c2 and when we find an element not less than c1 or c2 then we can surely say true or else false. We DO NOT care about the actual elements here so we can safely ignore them to just return true or false.

*/


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    int c1 = INT_MAX, c2 = INT_MAX;
    for (int x : nums) 
    {
        if (x <= c1)
            c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
        else if (x <= c2)   // here when x > c1, i.e. x might be either c2 or c3
            c2 = x;           // x is better than the current c2, store it
        else             // here when we have/had c1 < c2 already and x > c2
            return true;      // the increasing subsequence of 3 elements exists
    }
    return false;
   }
};
