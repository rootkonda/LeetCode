/**
A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:

For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

Return the length of a maximum size turbulent subarray of A.

1. Keep two pointers, less and more.
2. less++ and more++ and always maintain other pointer 0 if one is incremented.
3. If anyone of the pointers is greater than 1 then calculate the maximum of answer and length of the subarray.
4. If both elements are equal then move the start position to i+1.
**/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) 
    {
        int less = 0;
        int more = 0;
        int ans = 1;
        int start = 0;
        int len = A.size();
        for(int i=0;i+1<len;i++)
        {
            if(A[i]>A[i+1])
            {
                if(less==0)
                    less++;
                else
                {
                    ans = max(ans,i-start+1);
                    start = i;
                    less=1;
                }   
                if(more>0)
                    more--;
            }
            else if(A[i]<A[i+1])
            {
                if(more==0)
                    more++;
                else
                {
                    ans = max(ans,i-start+1);
                    start = i;
                    more=1;
                }
                if(less>0)
                    less--;
            }
            else
            {
                ans = max(ans,i-start+1);
                start = i+1;
                more=0;
                less=0;
            }  
        }
        if(more or less)
            ans = max(ans,len-start);
        return ans;
    }
};

//9<4
