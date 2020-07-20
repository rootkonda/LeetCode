/*

Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa (in other words s2 can break s1).

A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.


1. Mark the alphabets in a and b array for s1 and s2.
2. We just have to check whether each alphabet in s1 has atleast a same alphabet or closest greater alphabet in s2 and once we found it just decrement it to avoid reconsidering it.
If this is true for every alphabet in s1 then we return true or else false.
3. We repeat the step 2 for s2 in s1 when s1 is false.
*/


class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) 
    {
        vector<int> a(26);
        vector<int> b(26);
        int n = s1.size();
        for(int i=0;i<n;i++) 
        {
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        bool r1=true,r2=true;
        for(int i=0;i<n and r1;i++)
        {
            int j=s1[i]-'a';
            for(;j<26 and !b[j];j++);
            
            if(j==26)
                r1=false;
            else
                b[j]--;
        }
        for(int i=0;i<n and (!r1 and r2);i++)
        {
            int j=s2[i]-'a';
            for(;j<26 and !a[j];j++);
            
            if(j==26)
                r2=false;
            else
                a[j]--;
        }
        return r1 or r2;
    }
};
