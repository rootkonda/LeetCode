/**Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?

Note:

All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.

Approach:

Two pointers. One to go from starting till the end. Other one to update the original array with count.

**/


class Solution {
public:
    int compress(vector<char>& chars) {
        
        int count = 1;
        int i = 0;
        int idx = 0;
        while(i<chars.size())
        {
            chars[idx++]=chars[i];
            while(i+1<chars.size() and chars[i]==chars[i+1])
            {
                count++;
                i++;
            }
            if(count>1)
            {
                string temp = to_string(count);
                for(int i=0;i<temp.size();i++)
                    chars[idx++]=temp[i];
            }
            count=1;
            i++;
        }
        return idx;
    }
};
