/*
There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Explanation
-----------
We have two windows here, say we choose left window of size k i.e. initially we find the sum of first k elements and keep it as max sum. Hence, the right sum will be zero intially and also the right window starts from the back.
Each iteration we have to remove last element from left window and add the next last element from the back to the sum. We can keep them in left_sum and right_sum.
Now reduce the size of the left window and right window for next iteration.
Each iteration check which combination is maximum.
*/

class Solution {
public:
    int maxScore(vector<int>& points, int k) 
    {
        int n = (int)points.size();
        int left_window = k-1; //(0 to k-1) is of size 3 when we always choose only left elements.
        int right_window = n-1; // pointing to last element
        int left_sum = accumulate(points.begin(),points.begin()+k,0);
        int right_sum = 0;
        int ans = left_sum;
        while(left_window>=0)
        {
            left_sum-=points[left_window];
            right_sum+=points[right_window];
            
            left_window--;
            right_window--;
            
            ans = max(ans,left_sum+right_sum); // Step 5 above
        }
        return ans;
    }
};

