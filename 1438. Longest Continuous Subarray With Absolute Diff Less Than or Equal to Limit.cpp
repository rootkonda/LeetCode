/*



First of all, why we use only Min/Max elements in a subarray to check the limit ? Its kind of obvious, because if we compare difference between minimum and maximum elements in a subarray and if thats within the limit, then all elements within that range will also be in that limit.
Say we have left and right pointers, where right pointer is constantly moving towards the end of array and left pointer only moved when the limit is exceeded.
Min queue/multiset - Always have elements in ascending order, so minimum element first.
Max queue/multiset - Always have elements in descending order, so maximum element first.
Starting from zero, we keep going right towards end and for each element in the right we have to check whats the max and min elements so far after considering the current right element. Once we have that, check if that breaks the limit. If so then we have to move the left pointer and make sure to remove the element pointed by left pointer before moving. This is because this element is not valid anymore for comparison. IMPORTANT: Difference between the right and left pointer will be our max subarray length. This difference is always in non-decreasing order, which means the difference will never go down, it either stays same or increase if there is a new window of size more than exisiting one.
How is this working? It has three parts here:
Say the longest subarray appears at the prefix part of the given array, then the right pointer keeps incrementing until it breaks the limit. The moment it breaks that limit, we are going to move the left pointer only once, which is inline with the right pointer. i.e. 1,2,3,4,8 with limit 5 then when right points to 8 then we have to move the left pointer from index 0 to index 1 and gives the actual window size of 4(right-left -- (1,2,3,4)). Hence moving the left pointer only once guarantees the window length to be non-decreasing.
Say the longest subarray appears at the suffix part of the given array, then the left pointer will keep getting incremented until it reaches the index where the difference between right and left doesn't break the limit condition.
Say the longest subarray appears in between the start and end of given array, then the left pointer is NOT incremented until the window size of longest subarray is complete and for rest of the right elements, both the right and left pointers will be moved in order to maintain the longest window size.
If this is clear, then we can say that our answer is right-left, which is our longest subarray length satisfying our limit constraint.


https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/discuss/609771/JavaC%2B%2BPython-Deques-O(N)
*/

C++ - Deque

class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        deque<int> maxd, mind;
        int i = 0, j;
        for (j = 0; j < A.size(); ++j) {
            while (!maxd.empty() && A[j] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && A[j] < mind.back()) mind.pop_back();
            maxd.push_back(A[j]);
            mind.push_back(A[j]);
            if (maxd.front() - mind.front() > limit) {
                if (maxd.front() == A[i]) maxd.pop_front();
                if (mind.front() == A[i]) mind.pop_front();
                ++i;
            }
        }
        return j - i;
    }
};

Sliding window Approach - Java Solution

public int longestSubarray(int[] nums, int limit) {
    int start = 0;
    int end = 0;
    int res = Integer.MIN_VALUE;
    int max = Integer.MIN_VALUE;
    int min = Integer.MAX_VALUE;
    int n = nums.length;

    while (start < n && end < n) {
	/*Update the min and max of that window to calculate the abs diff*/
      min = Math.min(min, Math.min(nums[start], nums[end]));
      max = Math.max(max, Math.max(nums[start], nums[end]));
	  
	/*if abs diff is less than limit. Simply update the answer and increment the end of window*/
      if (Math.abs(max - min) <= limit) {
        res = Math.max(res, end - start + 1);
        end++;
      } else {
	  /*if abs diff in greater than limit. Then no need to check for remaining windows with this starting 
	  point. So reset the start & end. Also reset min & max because you don't want min & max from 
	  previous windows*/
        start++;
        end = start;
        min = nums[start];
        max = nums[start];
      }
    }
    return res;
    }
