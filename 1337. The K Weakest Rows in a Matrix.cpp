/**
Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j. Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

Simple. Set of pairs.
 
**/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        set<pair<int,int>> indices;
        int r=mat.size();
        int c=mat[0].size();
        int sum=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                if(mat[i][j]==1)
                    sum++;
            indices.insert(make_pair(sum,i));
            sum=0;
        }
        vector<int> ans;
        for(auto itr=indices.begin();itr!=indices.end();itr++)
        {
            if(k>0)
                ans.push_back(itr->second);
            else
               break;
            k--;
        }
        return ans;
    }
};
