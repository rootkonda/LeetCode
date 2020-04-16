/**
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Sliding window approach but using queue.
1. For every element, check if the product is k.
2. If it is less then add it to the subarray.
3. When it is >=k, then calculate the number of subarrays can be calculated in two ways:
    1. Total size of the subarray-1
    2. n*(n+1)/2 - Number of subarrays excluding individual elements.
    3. If we calculate with subtracting 1 from total number of elements, then it means excluding the individual elements.

    
    3. other way is, end-start+1; easier.
**/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(!k)
            return 0;
        long long ans = 0;
        long product = 1;
        long long n;
        queue<int> elements,e;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<k)
            {
                product = product*nums[i];
                if(product >= k)
                {   
                    while(!elements.empty() and product>=k)
                    {
                        n = elements.size()-1;
                        ans+=n;
                        product/=elements.front();
                        elements.pop();
                    }
                }
                elements.push(nums[i]);   
            }
            else
            {
                ans--; // To avoid double counting at the end.
                n = elements.size()-1;
                ans+=(n*(n+1)/2);
                elements = e; // clear the queue;
            }
                
        }
        n = elements.size()-1;
        ans+=(n*(n+1)/2);
        ans += nums.size();
        return ans;
    }
};

