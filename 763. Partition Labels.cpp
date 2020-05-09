/**
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.


**/



class Solution {
public:
    vector<int> partitionLabels(string S) 
    {
        vector<pair<int,int>> a(26,{-1,-1}); // Start and End of a character in the given string.
        int index=0;
        int start=0;
        int end = 0;
        int i=0;
        vector<int> ans;
        for(int i=0;i<S.size();i++)
        {
            index = S[i]-'a';
            if(a[index].first==-1) //When this character appears for the first time
            {
                a[index].first = i; //Start position of this character in the given string.
                a[index].second = i; // End position of this character in the given string.
            }
            else // When the same character appears again
                a[index].second = i; //Keep updating the end position of this character as it appears again and again.
        }
        while(i<S.size())
        {
            index = S[i]-'a';
            start = a[index].first; //Set the start of a character
            end = a[index].second; //Set the end of a character
            int j = start+1;
            while(end<S.size() and j<end) // Iterate within the start and end of this character range until we find an end, which is greater than current end. If so, update the end with greater value. This is because we cannot split this character into two parts, if we do so then we will violate the given constraints.
            {
                end = max(end,a[S[j]-'a'].second);
                j++;
            }
            ans.push_back(end-start+1); //Difference between end and start is the length of this part which can be formed.
            i = end+1; //Next part starts after the end character, as the end character is already included in the previous part.
        }
        return ans;
    }
};
