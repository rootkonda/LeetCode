/**

Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.


Solution:

https://leetcode.com/problems/rotate-function/discuss/531675/Sliding-window-approach-in-C%2B%2B
A = [4, 3, 2, 6]

All the positions when rotated can be represented using the array : [4, 3, 2, 6, 4, 3, 2, 6] that is array A repeated twice.


idx : 0 1 2 3 4 5 6 7
arr : 4 3 2 6 4 3 2 6

All rotations :

4 3 2 6 -> 0 to 3

3 2 6 4 -> 1 to 4

2 6 4 3 -> 2 to 5

6 4 3 2 -> 3 to 6

fn first calculates the answer for the first permutation which is [4, 3, 2, 6] = 25

Moving to next permutation which is [3, 2, 6, 4] we see we're removing (0*4) and adding (4*4) when sliding on the extended array.

But since our answer would now be having (1*3 + 2*2 + 3*6 + 4*4) which is just array_sum + (0*3 + 1*2 + 2*6 + 3*4) we would have to subtract the array_sum once at each iteration from our answer;

**/


class Solution {
 public:
     int maxRotateFunction(vector<int>& A)
     {
         int len = A.size();
         if(len==0)
             return 0;
         
         long sum = 0;
         long fn = 0;
         for(int i=0;i<len;i++)
         {
             sum+=A[i];
             fn+= (i*A[i]);
         }
         long ans = fn;
         long left=1;
         long right;
         while(left<len)
         {
             right = left+len-1;
             long rmv = (left-1)*A[left-1];
             long add = (right*A[right%len]);
             fn = fn-rmv+add-sum;
             ans = max(fn,ans);
             left++;
         }
         return (int)ans;
     }
 };
