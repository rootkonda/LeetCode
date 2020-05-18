/*
Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 Constraints:

1 <= arr.length <= 10^5
arr.length is even.
1 <= arr[i] <= 10^5

*/



class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        int n = (int)arr.size();
        int half = n>>1;
        unordered_map<int,int> freq;
        map<int,int,greater<int>> fmap;
        for(auto num : arr) // calculate the frequencies of each element in the array
            freq[num]++; 
        for(auto itr:freq) // Prepare a frequency map for the list of frequencies calculated above
            fmap[itr.second]++;

        int curr=0;
        int count = 0;
        for(auto itr : fmap) // Go thru the frequency of frequencies
        {
            if(curr>=half)
                return count;
            else
            {
                if(itr.second==1) // If there is only one of this frequency then add the frequency itself
                {
                    count++;
                    curr+= itr.first;
                }
                else //If there is a frequency which is more than once, then keep adding the actual frequency until the frequency of this frequency is reduced to zero or if we reached the target.
                {
                    int j = itr.second;
                    while(j-->0 and curr<half)
                    {
                        curr+=itr.first;
                        count++;
                    }
                        
                }
            }
        }
        return count;
        
    }
};
