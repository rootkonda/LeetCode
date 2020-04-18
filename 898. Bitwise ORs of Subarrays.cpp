/**
We have an array A of non-negative integers.

For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j), we take the bitwise OR of all the elements in B, obtaining a result A[i] | A[i+1] | ... | A[j].

Return the number of possible results.  (Results that occur more than once are only counted once in the final answer.)

Idea is to take OR's of all subarrays and save those results but in a bit efficient way by comparing last element of the vector with the new XOR result.

// The basic idea is, for each element, enumerate and save all possible ORs result of all possible sub arrays end with it.
// E.g. For A[i], all possible sub array end with it is: {A[i]}, {A[i], A[i-1]}, .. {A[i], A[i-1],..A[0]}.
// The process is simply using A[i] to take OR operation with all sub arrays end with previous element A[i-1].
// Note, the ORs result of those sub arrays are increasing, i.e. {A[i-1]} <= {A[i-1], A[i-2]} <= .. <= {A[i-1], A[i-2],..A[0]}
// And so do the ORs result of the sub arrays end with A[i]. 
// So when we take OR operation between A[i] and previous sub arrays' OR results, we just need check if the new element is increased compare with the last result.
// E.g. if OR result of {A[i], A[i-1], A[i-2]} is greater than {A[i], A[i-1]}
// We can put all the ORs result into a vector, and remember the start and end position of the results of sub arrays end with previous element.
// So next time we only enumerate the results in this range.

https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss/165859/C%2B%2B-O(kN)-solution
https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss/166832/C%2B%2B-simplest-fastest-)-(224-ms)
**/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        vector<int> or_results;
        int i = 0, j = 0;
        for(auto a : A)
        {
            int start = or_results.size(); // Start of the next subarray, This will always point to the original previous element in the original array.
            or_results.emplace_back(a);
            for(int k = i; k < j; k++)
            { 
                int a2 = or_results[k] | a; This OR happens between previous element and current element.
                if(a2 > or_results.back()) // We insert the new XOR value into vector only if last element is smaller than this. Hence we are saving the unique values and remove the duplicates.XORing elements of all subarrays will result in monotone increasing values.This is the key here.
                    or_results.emplace_back(a2); // Just adding it to the end.
            }
            i = start, j = or_results.size();
        }
        return unordered_set<int>(or_results.begin(), or_results.end()).size(); Needed to avoid the duplicates.
    }
};
