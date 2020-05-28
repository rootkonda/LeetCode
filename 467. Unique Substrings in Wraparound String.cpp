/*
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.
1. Since the substrings are all continuous(a-zz-a and so on), we can track max length of substring with respect to one of the 26 alphabets at any point.
2. For every character, check whether it is continuous. If so, then increment the count or reset count to 1. For every character update the max length of a substring for this character.
3. Finally add all the values from 0-26 and return the answer.

*/
class Solution {
public:
    int findSubstringInWraproundString(string p) 
    {
        int count = 0;
        int answer = 0;
        vector<int> mx(26,0);
        for(int i=0;i<p.size();i++)
        {
            int diff = i>0 ? (p[i]-p[i-1]) : 0;
            if(diff==1 or abs(diff)==25)
               count++;
            else
                count=1;
            int index = p[i]-'a';
            mx[index] = max(mx[index],count);
        }
        
        for(auto cnt : mx)
            answer+=cnt;
        return answer;
    }
};
