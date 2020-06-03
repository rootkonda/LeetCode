/*
We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef","vyz"].

Suppose we chose a set of deletion indices D such that after deletions, the final array has its elements in lexicographic order (A[0] <= A[1] <= A[2] ... <= A[A.length - 1]).

Return the minimum possible value of D.length.


Brute Force Solution.
Lexicographical Order for two strings is that if two characters are same then we move on until we see str[i]<str[j] and if we find then we skip this. If we find str[i] > str[j] then we have to delete this character so please make a note in a set and then restart the whole process from the first string as we have to consider the deleted index this time.
*/

class Solution {
public:
    int minDeletionSize(vector<string>& A) 
    {
        int n = A.size();
        int sz = A[0].size();
        unordered_set<int> del;
        for(int i=1;i<n;i++)
        {
            for(int k=0;k<sz;k++)
            {
                if(del.count(k)>0 or A[i-1][k]==A[i][k])
                    continue;
                if(A[i-1][k]>A[i][k])
                {
                    del.insert(k);
                    i=0;
                }
                break;
            }
        }
        return del.size();
    }
};
