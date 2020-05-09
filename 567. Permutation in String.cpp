/**
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.


**/



class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> p(26,0);
        int left,j;
        int limit = (int)s1.size();
        int start = -1;
        vector<int> temp;
        for(auto c : s1)
            p[c-'a']++;
        
        int len = (int)s2.size();
        for(int i=0;i<len;i++)
        {
            temp = p;
            left = (start==-1 ? i : start);
            j =0;
            while(left<len and j<limit)
            {
                if(temp[s2[left]-'a']>0)
                    temp[s2[left]-'a']--;
                else
                {
                    if(p[s2[left]-'a']==0)
                        start = left+1;
                    else
                        start = -1;
                    break;
                }
                    
                left++;
                j++;
            }
            if(j==limit)
                return true;
        }
        return false;
    }
};
