/*
We have two integer sequences A and B of the same non-zero length.

We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.

At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)

Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is guaranteed that the given input always makes it possible.

Explanation:
------------
For each ith index, we have two options - either swap or do not swap them. We have to calculate the moves for both of them until the last index.

We have initialized two arrays with MAX value, which is N as we are going to calculate minimum.
For index 0, if we swap then swap[0] = 1 and if we do not swap then noswap[0] =0
For index 1 and all other indices, we check two conditions and determine the values of noswap[i] and swap[i]:
In a normal scenario(First If Condition, either swap them both or don't), where the given two numbers in both the arrays are sorted i.e. A[i-1]<A[i] and B[i-1]<B[i]. Our goal is to keep them sorted. However we calculate the noswap[1] and swap[1] like this:
a. If we have swapped A[0] and B[0] and we are also swapping A[1] and B[1] then swap[1] will be count of previous swaps plus 1. i.e. swap[i] = swap[i-1]+1;
b. Similarly, if we did not swap A[0] and B[0] and we are also not swapping A[1] and B[1] so moves remain same as previous noswap[i] = noswap[i-1];
c. The key point here is either swap A[0] and A[1] elements with B[0] and B[1] or do not swap them both. We cannot choose either or here because when you think about it, two elements are sorted in A and two elements are sorted in B but we don't know if swapping one of them alone will hold this property true. That's why we have to swap them both or don't.
Second if condition, swap either one of them i.e 0th or 1st when the condition satisfies.
a. For example, if we swap A[0] and B[0] then we have to check if B[0] < A[1] and similarly A[0]<B[1] because thats how its gonna be after swapping and they have to be strictly increasing.
b. If we swap A[1] with B[1] then we cannot swap A[0] with B[0](we have already considered that scenario in the first If condition). Now we try this scenario of swapping only one of them either A[0] or A[1]. So if we swap A[1] and B[1], then swap[1] = min(swap[1],noswap[0]+1), noswap[0]+1 is because ony A[1] is swapped so +1 with noswap[0] as A[0] is not swapped.
c. Similarly, if we do not swap A[1] and B[1] then noswap[1] = min(noswap[1],swap[0]) we are doing +1 because current element is not swapped.
Finally, the minimum of swap[n-1] and noswap[n-1] is the answer.

*/
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        vector<int> swap(n,n);
        vector<int> noswap(n,n);
        swap[0] = 1;
        noswap[0] = 0;
        for(int i=1;i<n;i++)
        {
           if(A[i-1]<A[i] and B[i-1]<B[i])
           {
               swap[i] = swap[i-1]+1;
               noswap[i] = noswap[i-1];
           }
           if(A[i-1]<B[i] and B[i-1]<A[i])
           {
               swap[i] = min(noswap[i-1]+1,swap[i]);
               noswap[i] = min(swap[i-1],noswap[i]);
           }
        }
        return min(swap[n-1],noswap[n-1]);
    }
};

