/*
Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.

Binary search O(NlogMax(A)).
In order to ruduce the difficulty, it constrains A[i] < 10 ^ 5.

In this solution,
we sort the input and compared A[i] with target one by one.

Sort the array A in decreasing order.
We try to make all values in A to be the min(A) (the last element)
If target >= min(A) * n, we doesn't hit our target yet.
We should continue to try a value bigger.
So we pop the min(A) value.
Consider that it won't be affected anymore,
we can remove it from target by target -= A.pop()
We continue doing step 2-4, until the next number is too big for target.
We split the the target evenly, depending on the number of element left in A
At this point, @bobalice help explain the round part:
if A is empty means its impossible to reach target so we just return maximum element.
If A is not empty, intuitively the answer should be the nearest integer to target / len(A).

Since we need to return the minimum such integer if there is a tie,
if target / len(A) has 0.5 we should round down,


*/

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) 
    {
        sort(arr.begin(),arr.end());
        int idx=0;
        int n = arr.size();
        while(idx<n and target>arr[idx]*(n-idx))
            target-=arr[idx++];
        return idx==n ? arr[n-1] : (int)round(((target-0.0001)/(n-idx)));
    }
};

