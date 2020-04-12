/**

Write a function that takes a string as input and reverse only the vowels of a string.
Note:
The vowels does not include the letter "y".

Approach:

First record all the indices of vowels in a string. Secondly, loop thru those indices with two pointers from left and right and keep swapping those characters.
**/

class Solution {
public:
    string reverseVowels(string s) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> indices;
        if(s.length()==0)
            return "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='e' or s[i]=='i' or s[i]=='a' or s[i]=='o' or s[i]=='u')
                indices.push_back(i);
            if(s[i]=='E' or s[i]=='I' or s[i]=='A' or s[i]=='O' or s[i]=='U')
                indices.push_back(i);
        }
        if(indices.size()==0)
            return s;
        int left=0,right=indices.size()-1;
        int i=indices[left];
        int j=indices[right];
        while(j>i)
        {
            char t=s[i];
            s[i]=s[j];
            s[j]=t;
            i=indices[++left];
            j=indices[--right];
        }
            
        return s;
    }
};
