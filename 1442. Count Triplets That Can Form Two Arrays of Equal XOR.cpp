/*
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.
Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 10^8

As given in the question, If a==b then a XOR b will be 0. The solution is based on this XOR property.
For each element in the array try to XOR with every other element and when we encounter 0, it means there is a subarray XOR which results in 0 and then we have to just calculate the number of triplets that can be formed with that size of subarray. i.e. (j-i) gives us the number of possible triplets.
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) 
    {
        int ans=0;
        int bit=0;
        for(int i=0;i<arr.size();i++)
        {
            bit^=arr[i];
            for(int j=i+1;j<arr.size();j++)
            {
                bit^=arr[j];
                if(bit==0)
                    ans+=(j-i);
            }
            bit=0;
        }
        return ans;
    }
};
