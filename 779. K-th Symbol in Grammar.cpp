/*
On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).


https://leetcode.com/problems/k-th-symbol-in-grammar/discuss/405670/C%2B%2B-and-x86-assembler-solutions-with-explanation


Number of bits set in k-1 is odd or even will be our answer.
This is because the number of bits set at a given K-1th index is the value.

Notice that the sequence can be constructed as follows:

s_0 = 0
s_1 = concat(s_0, complement(s_0)) = 01
s_2 = concat(s_1, complement(s_1)) = 0110
s_3 = concat(s_2, complement(s_2)) = 01101001
...

This means that the kth element of the sequence (where k is 0-based) is the complement/opposite of the (k-p)th element, where p is the greatest power of two less than or equal to k. It follows that the answer can be found by starting with 0 and flipping the value for every bit in k. This is just the parity of the bit count.

0 -> 0 -> 0 bits -> parity 0
1 -> 1 -> 1 bit -> parity 1
2 -> 10 -> 1 bit -> parity 1
3 -> 11 -> 2 bits -> parity 0
4 -> 100 -> 1 bit -> parity 1
5 -> 101 -> 2 bits -> parity 0
6 -> 110 -> 2 bits -> parity 0
7 -> 111 -> 3 bits -> parity 1
*/


class Solution {
public:
    int kthGrammar(int N, int K) 
    {
        return std::bitset<32>(K-1).count() & 1;  
    }
};
