/**

We are given an array A of positive integers, and two positive integers L and R (L <= R).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.


    //for an element there are 3 cases possible:
        //case 1 :element is greater than R. In this case,there will be no valid subarrays ending with this element
        //        because all the subarrays ending with this element will have a maximum value >=current element 
        //        hence will not be valid.
        //case 2: element is less than L. In this case element itself will not form a valid subarray but can append
        //        to all the valid subarrays ending with previous element.hence number of valid subarrays ending 
        //        with current element will be equal to the number of valid subarrays ending with previous element.
        //        this is possible because a valid subarray will have maximum value at least L and at most R and since
        //        current element's value is less than L,max value of the subarray will not be changed when this element
        //        is appended to the end.
        //case 3: element at least L and at most R.In this case element itself will form a valid subarray plus it will
        //        also form other valid subarrays as follows: we'll look for recent/latest element having value >R.all
        //        the elements between this element and current element(including current element) will form valid sub-
**/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) 
    {
        int index = -1; // To maintain the index of value > R. -1 is because if the first element is valid then you have to add 1 to the answer.
        int ans = 0;
        int last = 0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]<L)
                ans+=last; //If there is a element smaller than L then you can add the last count to ans because adding this wont change the maximum of the subarray.
            else if(A[i]>R)
            {
                index = i; // To take the difference between next valid element to invalid element and add it to answer.
                last = 0; // Reset the last count because this element is >R so last count will not be valid to consider.
            }
            else
            {
                ans+=(i-index);
                last=i-index;
            }
        }
        return ans;
            
    }
};
