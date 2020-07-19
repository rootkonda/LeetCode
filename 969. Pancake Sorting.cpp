/*
Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.

Note:

1 <= A.length <= 100
A[i] is a permutation of [1, 2, ..., A.length]

1.For every flip, take the maximum number and reverse all numbers upto the index of max number. This will bring the max number to 0th index.
2.Next reverse first max number elements to place the max number in its appropriate index position
3.So here we flip twice,hence add two values to the resultant array
*/
class Solution {
public:
     vector<int> pancakeSort(vector<int> A) {
        vector<int> res;
        int x,i;
        for (x = A.size(); x > 0; --x) {
            for (i = 0; A[i] != x; ++i);
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + x);
            res.push_back(x);
        }
        return res;
    }
};
