/**
Given a string s. You should re-order the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.

Simple.
1. use alphabet array of 26 to solve this problem.
2. temp_letters[25  - i] or i+'a'.

**/


class Solution {
public:
    string sortString(string s) 
    {
        int temp_letters[26] = {0};
        for (auto i:s)
            temp_letters[ i - 'a']++;
        
        string ans = "";
        int i = 0;
        while(true) 
        {
            if(ans.size() == s.size())
                break;
            i = 0;
        
            while(true) 
            {
                if(temp_letters[i] > 0 ) {
                    ans += i + 'a';
                    temp_letters[i]--;
                }
                i++;
                if(i == 26)
                    break;;
            }
            i = 0;
            while(true) 
            {
                if(temp_letters[25  - i] > 0 ) {
                    ans += 'z' - i;
                    temp_letters[25 - i]--;
                }
                i++;
                if(i == 26)
                    break;;
            }
        }
        return ans;
    }
};
