/**
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

Modified version of kadane's algorithm. Maintain the skipped sum and compare usual sum and skipped sum.
**/



class Solution {
public:
    int maximumSum(vector<int>& arr) 
    {
        if (arr.size() == 0) 
            return 0;
        int max_sum = arr[0];
        int current_sum = arr[0];
        int skipped_current_sum = 0;
        for (int i = 1; i < arr.size(); ++i) 
        {
            skipped_current_sum = max(skipped_current_sum + arr[i], current_sum);// If max is current_sum then it means ith element is deleted. For every element we are checking the skipped sum with the current sum, if at any point, the current sum is bigger then the skipped sum becomes current sum so there is only one deletion.
            current_sum = max(arr[i], current_sum + arr[i]); // usual kadane's algorithm
            max_sum = max(max_sum, max(current_sum, skipped_current_sum));//whichever is bigger thats the max sum.
        }
        return max_sum;      
    }
};
