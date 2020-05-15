/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.


Given n digits there will be total of (n * (n-1) * ... * 2 * 1) different permutations. - the 1st digit you have n options, 2nd digit you have n-1, ... last digit you only have 1 option.
Your choices to pick different number at each digit will form different groups of permutations. Example: Your choice for the n different number at the 1st digit will result in n groups of permutations, start with 1 ~ n. and each group will contain (n-1) * ... * 2 * 1) permutations which can be further divided into n-1 groups, and so on...
Given 0-based sequence index k, what is the 1st number of the kth permutation depend on which group it is in, and this can be calculated by k / $group_size, which is k / ((n-1)*...*2*1), and within that group, its index will be k % ((n-1)*...*2*1), and k should be updated as that.
Once 1st number is determined, the 2nd number can be determined by which sub-group it belongs to within the first level group, which again can be calculated by k / $group_size.
*/



class Solution {
public:
    string getPermutation(int n, int k) 
    {
        int weight=1;
        string digits = "123456789";
        for(int i=1;i<=n;i++)
            weight*=i;
        --k%=weight; // --k is because of 0-based index in the string above and to calculate which group the first character is in.
        string ans(n,'\0');
        for(int i=0;i<n;i++)
        {
            weight = weight/(n-i);
            int d = k/weight;
            ans[i] = digits[d];
            digits.erase(d,1);
            k%=weight;
        }
        return ans;
    }
};
