/*
Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.
Note:

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000

Sort the vector.
Assuming there is a point, on the left of the point, all elements add K, on the right of the point, all elements substract K, check each possible point. (a point is between two numbers).
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int res = A[A.size() - 1] - A[0];
        int left = A[0] + K, right = A[A.size() - 1] - K;
        for (int i = 0; i < A.size() - 1; i++) {
            int maxi = max(A[i] + K, right), mini = min(left, A[i + 1] - K);
            res = min(res, maxi - mini);
        }
        return res;
    }
};
More explanation:
Cause there are two segments (A[0]+K, A[1]+K, ..., A[i]+K, A[i+1]-K, ..., A[n]-K), the first one is on the left of the current point (A[i] + K is the last element of the first segment), the second one is on the right of the current point (A[i + 1] - K is the first element of the second segment). For the first segment, the smallest element is left, the largest is A[i] + K; For the second segment, A[i + 1] - K is the smallest element, the largest is right. Thus, for each point, the largest element should be either A[i] + K or right, the smallest element should be either left or A[i + 1] - K.

*/


class Solution {
public:
    int smallestRangeII(vector<int>& A, int k) 
    {
        sort(A.begin(),A.end());
        int ans = A.back() - A.front();
        int left = A.front()+k;
        int right = A.back()-k;
        
        for(int i=0;i<A.size()-1;i++)
            ans = min(ans,max(right,A[i]+k)-min(left,A[i+1]-k));

        return ans;
    }
};

