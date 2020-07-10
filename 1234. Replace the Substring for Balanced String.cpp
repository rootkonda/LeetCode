/*
You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.

A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.

Return 0 if the string is already balanced.

 

*/


class Solution {
public:
    int balancedString(string s) 
    {
        vector<int> count(128,0);
        int target = s.size()>>2;
        for(auto c : s)
            count[c]++; // Count q,w,e,r characters
        // Find the remaining characters after the required target
        count['Q']-=target; 
        count['W']-=target;
        count['E']-=target;
        count['R']-=target;
        
        if(count['Q']<=0 and count['W']<=0 and count['E']<=0 and count['R']<=0) //If everything is less than or equal to 0 then its already balanced.
            return 0;
        
        int left = 0;
        int right = 0;
        int ans = s.size();
        
        while(right<s.size()) //sliding window
        {
            count[s[right++]]--; // Keep moving to right and subtract the count of characters and when we reach a position where count becomes 0 or less means we have a window now. Once we found that window then keep moving the left until the count stays 0 or less and then findout the minimum length 
            
            if(count['Q']<=0 and count['W']<=0 and count['E']<=0 and count['R']<=0)
            {
                while(count['Q']<=0 and count['W']<=0 and count['E']<=0 and count['R']<=0)
                     count[s[left++]]++;
                ans = min(ans, right-left+1);
            }
            
        }
        return ans;
    }
};
