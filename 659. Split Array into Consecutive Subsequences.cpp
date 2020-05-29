/*
Given an array nums sorted in ascending order, return true if and only if you can split it into 1 or more subsequences such that each subsequence consists of consecutive integers and has length at least 3.


Explanation
-----------
Idea is not have any subsequences of length 1 or 2 and only have lengths>=3. And also for every new number we should first give priority to subsequences which are less than 3 instead of adding the new number to subsequences >=3.

Priority is ordered as follows:

Add current number to all subsequences of length 1
Add current number to all subsequences of length 2
Add current number to all subsequences of length 3 or more.
We have to maintain the following for current number and its previous number at any point in the iteration.

Number of subsequences of length 1, which is represented as p1(previous) and c1(current)
Number of subsequences of length 2, which is represented as p2(previous) and c2(current)
Number of subsequences of length >=3, which is represented as p3(previous) and c3(current)
Few other important observations are:
Please note that we do not need to have the actual subsequences here, just knowing how many subsequences of lengths 1,2 and >=3 are available at every number is sufficient.

For every number, we have to first count how many occurences of that number is there in the given array. Next, we have to check if we can spread it across all the subsequences of length 1 and 2. If we cannot add the current number then we can immediately return false. This is because 1 or 2 length subsequences can never be extended if we cannot add the current number to all them as all numbers are sorted, the next number would be higher so it wont satisfy the consective numbers criteria mentioned. Hence this means the count of occurences of current number should always exceed total number of subsequences of length 1 and length 2.

If the count of a number is higher than the number of subsequences of lengths 1 and 2 so then we try to add it to the number of subsequences of length 3 or more. While adding to it, we have two things to consider:
a. count > (p1+p2+p3), then the remaining count of a number will be treated as subsequences of length 1.
b. count < p3 but count >(p1+2), in this case first do count-(p1+p2) and then add the remaining count to p3 and only the minimum of count and p3 will be considered as that would be valid for the next number.

We have to always check whether the current number is consective to the previous number, if not then we have to check at that if p1 or p2 is non-zero then immediately return false. What this means is we encountered non-consective number and at that point we have some number of subsequences of lengths 1 and 2 and this new number can never be added to them so they will stay as lengths 1 and 2.

For every number, we always update the c1,c2 and c3.
c1 = max(0,count-(p1+p2+p3)); - Gives the number of subsequences of length 1 after adding the current number to all previous lengths. if it goes -ve then there is no subsequence of length1 so 0.
c2 = p1; - previous number of subsequences of length 1 now becomes 2 by adding the current number. so just assign c2=p1.
c3 = p2+min(p3,count-(p1+p2)); - previous number of subsequences of length 2 now becomes 3 so c3 = p2 plus we have to consider how many subsequences of earlier p3 should be added. This depends on to how many subsequences of length 3 the current number can be added to. We have to add that many subsequences along with p2. We cannot simply add p3 because as that would mean invalid subsequence for next number if the count of current number is less than p3. Hence we always take min(p3,count-(p1+p2)).

Finally the answer depends on c1 and c2 being 0 or not. 0 means there are no subsequences of lengths 1 and 2 so everything is of lengths 3 or more.

Inspired/Taken from @fun4LeetCode's solution. Just wanted to share my understanding and explanation to it.

*/


class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        if(nums.size()<3)
            return false;
        int curr=0;
        int prev=0;
        int p1=0;
        int p2=0;
        int p3=0;
        
        int c1=0;
        int c2=0;
        int c3=0;
        int i=0;
        while(i<nums.size())
        {
            int count=0;
            p1=c1;p2=c2;p3=c3;
            prev=curr;
            curr = nums[i];
            while(i<nums.size() and nums[i]==curr)
            {
                i++;
                count++;
            }
            if(curr!=prev+1)
            {
                if(p1!=0 or p2!=0)
                    return false;
                c1=count;
                c2=0;
                c3=0;
            }
            else
            {
                if(count<p1+p2)
                    return false;
                c1 = max(0,count-(p1+p2+p3));
                c2 = p1;
                c3 = p2+min(p3,count-(p1+p2));
            }
        }
        return (c1==0 and c2==0);
    }
};
