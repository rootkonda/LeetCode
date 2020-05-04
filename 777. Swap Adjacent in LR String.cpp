/*      XL -> LX
        RX -> XR
        Based on those rules, L can move only left and R can move only right!
        With this in mind, every time we have an L in our start string we must
        also have an L already counted in our end string and at least one X to
        make the switch.
        On the other hand, if we have an R in our end string, we myst already have 
        an R in our start string and at least one X to make the switch.
        
Ref: 
https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/119647/Easy-to-understand-C%2B%2B-solution-with-detailed-explanation. --- Not entirely correct.
https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/231409/C%2B%2B-8ms-beats-100-one-pass-no-extra-memory.-Detailed-explanation! --- Not entirely correct.


https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/612851/Simple-C%2B%2B-Solution-with-explanation
*/


class Solution {
public:
    bool canTransform(string start, string end) 
    {
        int L=0,R=0;
        
        for(int i=0;i<start.size();i++)
        {
            if(start[i]=='L')
                L--,R=0; // Reset count of R to zero because the end[i] should have X now, if there is any other character then R becomes -ve and returns false;
            else if(start[i]=='R')
                R++,L=0; // Reset count of L to zero because end[i] should have X now, if there is any other character then L becomes -ve and returns false;
            
            if(end[i]=='L')
                L++;
            else if(end[i]=='R')
                R--;
            
            if(L<0 or R<0)
                return false;
        }
        if(L>0 or R>0)
            return false;
        return true; // If both L and R are zero then return true else return false;
    }
};


