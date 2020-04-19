/**
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Manacher's Algorithm:
1. We should prepare a new string by inserting a special character between characters and at start and end. Example, #a#b#c# for given string abc.
2. Additionally to that, we are also inserting '@' and '$' at the start and end, inorder to avoid boundary violation during the expansion to check for palindrome, when current pointer is at first or last characters.
3. Since we added two additional characters, start the loop from 1 and end before the last one.
4. Remember that, each value at p[i] is twice as big as original palindrome size. Hence in order to take the all possible palindromes for a given radius at a center. We should use (p[i]+1)/2.
5. According to manacher's algorithm, we should palindromic symmetricity property to fill the p array efficiently by copying its values from leftside of the center. While copying, make sure these:
  1. current pointer is less than right boundary
  2. find the mirror value at left and assign the minimum of left and right-current pointer value into current pointer position.
  3. when current pointer+p[i] >right then reset the center to i and right boundary as i+p[i]
Refernces:
https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/
https://gist.githubusercontent.com/graphoarty/88374bbf4e621f27c029b946f026a707/raw/5925a77e941b83e73f25dd2fec49c9a6e5c1249b/gistfile1.txt
https://www.youtube.com/watch?v=kbUiR5YWUpQ&t=627s
**/


class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if(s.size()==0)
            return "";
        string str;
        str.push_back('@');
        str.push_back('#');
        for(auto c : s)
        {
            str.push_back(c);
            str.push_back('#');
        }
        str.push_back('$');
        vector<int> p(str.size());
        int center = 0,right = 0;
        for(int i=1;i<str.size()-1;i++)
        {
            int i_mirror = center - (i-center);
            if(i<right)
                p[i] = min(right-i,p[i_mirror]);
            
            while(str[i+1+p[i]]==str[i-1-p[i]])
                p[i]++;
            
            if(i+p[i]>right)
            {
                center = i;
                right = i+p[i];
            }   
        }
        int ans = INT_MIN;
        string res="";
        int d = 0;
        for(int i=0;i<str.size();i++)
        {
            if(ans<p[i])
            {
                ans = p[i];
                res = s.substr((i-p[i])/2,p[i]); // start index and number of characters from start index.
            }   
        }
        return res;
    }
};
