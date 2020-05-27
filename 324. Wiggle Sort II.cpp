/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

Explanation
-----------

We can observe that odd indices should contain bigger values than its neighbors so even indices can contain smaller values. Keeping this in mind, we can first find the median element, which is the element which will be at median position if it were sorted. This will be our mid/pivot element against which we are going to rearrange our elements.

Using nth_element we rearrange the elements at median position and get that element
Now using partitioning algorithm we are going to rearrange our elements with slight modification on which indices we have to choose for swapping.
a. Elements greater than mid should be at odd indices(starting from 1st odd spot i.e. 1)
b. Elements lesser than mid should be at even indices(starting from back so 4 in case of 5 is our last index)
c. We can move on to next odd index for elements equal to mid.
When are done swapping odd indices with even from left and right, we can move on to even indices and repeat the above 3 steps.
This process will go until we reach an index which is less than right, which is when the cycle has completed i.e. reaching the odd index 1 again.
Inspired from https://en.wikipedia.org/wiki/Dutch_national_flag_problem
Inspired from @stefan pochmann's solution.
https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing
https://leetcode.com/problems/wiggle-sort-ii/discuss/77681/O(n)-time-O(1)-space-solution-with-detail-explanations
*/

class Solution {
public:
    int n;
    inline int get(int idx) // This technique is inspired from stefan as I was reading the discussions and also from Dutch National Flag problem from BacktoBackSWE and wiki as well.
    {
        //if n is even then, change it to next odd because when are done processing odd indices, we have to switch to even index starting from zero. When we reach last odd index and try to calculate next odd index then we have to take mod of n with odd number.
        //n|1 gives us the closest odd number
        
        int odd_index = 2*idx+1; // next odd index for a given current index
        int sz = n|1; // When odd_index crosses the last odd index then % sz will make it zero
        return odd_index%sz;
    }
    void wiggleSort(vector<int>& nums) 
    {
        n = (int)nums.size();
        //Find the value at median index in case if it is sorted, thats why we use nth_element STL
        auto itr = nums.begin()+(n>>1);
        nth_element(nums.begin(),itr,nums.end(),std::greater<int>()); 
        int mid = *itr;
        
        int low = 0; // Pointer to similar to curr(which points to odd indices) but this will always point to next available odd spot where we can swap when we find an element greater than mid (1st partition)
        int curr = 0;
        int high = n-1; // Pointer to the last element(conceptually, we assume this is the 3rd partition)
        
        while(curr<=high)
        {
            if(nums[get(curr)]>mid)
                swap(nums[get(curr)],nums[get(high--)]);
            else if(nums[get(curr)]<mid)
                swap(nums[get(low++)],nums[get(curr++)]);
            else
                curr++;
        }
    }
};
