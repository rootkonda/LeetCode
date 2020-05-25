/*
introduce some pattern firstly,

1. all positive : [1,2,3], k = 3, array_sum = 6
    return array_sum*3
2. all negative : [-1,-2], k = 2, array_sum = -3
    return 0
3. hybrid, with array_sum <= 0, [2,1,-3], k = 4, array_sum = 0
       [ 2,  1, -3, 2, 1, -3, 2, 1, -3, 2, 1, -3]
max sum  2   3  0   2  3  0   2  3   0   2  3  0
	return max_subarray_sum between [2,1,-3,2,1,-3] which is twice of original array
	so, return max_subarray_sum = 3
4. hybrid, with array_sum > 0, [2,-6,5], k =4, array_sum = 1
       [ 2, -6, 5, 2, -6, 5, 2, -6, 5, 2, -6, 5]
max sum  2   0  5  7   1  6  8   2  7  9   3  8
a. you can notice max subarray sum is getting bigger as k grows up.
b. with first 2 array, we can get max subarray sum is 8.
c. after that, with each new array, max_subarray_sum will increase by 1, which is array_sum
==>return (max_subarray_sum when k=2) + array_sum*(k-2)

Intuition
I guess you know how to solve max subarray sum (without circular).
If not, you can have a reference here: 53. Maximum Subarray


Explanation
So there are two case.
Case 1. The first is that the subarray take only a middle part, and we know how to find the max subarray sum.
Case2. The second is that the subarray take a part of head array and a part of tail array.
We can transfer this case to the first one.
The maximum result equals to the total sum minus the minimum subarray sum.


Here is a diagram by @motorix:
image

So the max subarray circular sum equals to
max(the max subarray sum, the total sum - the min subarray sum)


Prove of the second case
max(prefix+suffix)
= max(total sum - subarray)
= total sum + max(-subarray)
= total sum - min(subarray)


Corner case
Just one to pay attention:
If all numbers are negative, maxSum = max(A) and minSum = sum(A).
In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
According to the deacription, We need to return the max(A), instead of sum of am empty subarray.
So we return the maxSum to handle this corner case.


Complexity
One pass, time O(N)
No extra space, space O(1)

https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
https://leetcode.com/problems/k-concatenation-maximum-sum/discuss/383302/C%2B%2B-clean-code-beat-97-with-detailed-explanation
*/



