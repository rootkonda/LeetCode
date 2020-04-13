/**
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.

Approach - Idea is to first sort both arrays. Next, assign the biggest cookie to highest greed value. if there is no such greed value then loop the greed array until we find one.

**/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count = 0;
        int i=g.size()-1;
        int j=s.size()-1;
        while(i>=0 and j>=0)
        {
            if(s[j]>=g[i])
                count++;
            else
            {
                while(i>=0)
                {
                    if(s[j]>=g[i])
                    {
                        count++;
                        break;
                    }
                    i--;
                }
            }
            i--;
            j--;
        }
        return count;
    }
};

// 2 or more children has same greed factor ?
