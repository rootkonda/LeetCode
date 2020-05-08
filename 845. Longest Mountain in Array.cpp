/*
Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain


*/



class Solution {
public:
    int longestMountain(vector<int>& A) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans = 0;
        int left = 0;
        int right = 0;
        int count = 0;
        int len = A.size();
        while(left<len and right<len)
        {
            while(left+1<len and A[left]<A[left+1])
            {
                left++;
                count++; // Number of elements on the left of the peak
            }
            right = left;
            while(right+1<len and A[right]>A[right+1] and count>0) // count>0 is because go to the right only if there was atleast 1 element to the left of the peak
            {
                right++;
                count++; // Number of elements on the right of the peak
                ans = max(ans,count+1); +1 is because we need two elements for comparison so when we start with count=0 and count++ we need to use count+1;
            }
            if(count==0) // No mountain at all
                left++;
            else
                left=right; // one of the while loops above was entered. It may or may not have found the peak though but we have to start from where the right is.
            count=0; reset the count to zero for calculating the size of the next mountain range.
        }
        return ans;
    }
};
