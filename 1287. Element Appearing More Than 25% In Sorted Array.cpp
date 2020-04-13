/**
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

Return that integer.

Just count the occurences of each element and if it is greater than arr.size()/4 times.
**/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int sz=arr.size()/4;
        int i=0;
        if(arr.size()==1)
                return arr[0];
        int count=1;
        while(i+1<arr.size())
        {
            if(arr[i]==arr[i+1])
                count++;
            else if(count >sz)
                return arr[i];
            else
                count=1;       
            i++;  
        }
        if(count >sz)
            return arr[i-1];
        return 0;
    }
};
