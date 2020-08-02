/*

We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

https://leetcode.com/problems/global-and-local-inversions/discuss/113644/C%2B%2BJavaPython-Easy-and-Concise-Solution
To satisfy the global/local inversion equality, an element in the array should be larger than all previous elements, except the one right before it: A[i] > A[0]..A[i - 2].
All local inversions are global inversions.
If the number of global inversions is equal to the number of local inversions,
it means that all global inversions in permutations are local inversions.
It also means that we can not find A[i] > A[j] with i+2<=j.
In other words, max(A[i]) < A[i+2]

In this first solution, I traverse A and keep the current biggest number cmax.
Then I check the condition cmax < A[i+2]

Here come this solutions:

*/


class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
    for (auto i = 2, m = A[0]; i < A.size(); m = max(m, A[i - 1]), ++i) 
      if (A[i] < m) return false;
    return true;
}
};
/*
[1,2,0]
[1,0,2]
[1,0]
[0]
*/
