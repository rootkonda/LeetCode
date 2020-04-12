/**
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Approach:
Hours and Minutes loop. For each hour run a 0-59 loop and count the bits in hour and mins and check with num.
**/

class Solution {
public:
    vector<string> readBinaryWatch(int num) 
    { 
        vector<string> ans;
        string hour,mins;
        for(int i=0;i<12;i++)
        {
            bitset<32> hbits(i);
            for(int j=0;j<60;j++)
            {
                bitset<32> mbits(j);
               if( hbits.count()+mbits.count() == num )
               {
                   hour=to_string(hbits.to_ulong());
                   mins=to_string(mbits.to_ulong());
                   if(mins.size()==1)
                       mins = "0" + mins;
                   hour+=":";
                   hour+=mins;
                   ans.push_back(hour);
               }
            }
        }
        return ans;
        
    }
};
