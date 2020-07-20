/*
Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed.

For each prefix in the search word, store the matching words in a set and the prefixes in a map. This by default keeps the strings in sorted order.
*/
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string sw) 
    {
        map<string,set<string>> prefix;
        vector<vector<string>> ans(sw.size(),vector<string>{});
        for(auto prod : products)
        {
            string str="";
            for(int i=0;i<sw.size() and i<prod.size();i++)
            {
                if(prod[i]==sw[i])
                {
                    str.push_back(sw[i]);
                    if(prefix.count(str))
                        prefix[str].insert(prod);
                    else
                        prefix[str].insert(prod);
                }
                else
                    break;
            }
        }
        int idx=0;
        for(auto itr : prefix)
        {
            vector<string> t(itr.second.begin(),itr.second.end());
            for(int i=0;i<3 and i<t.size();i++)
                ans[idx].push_back(t[i]);
            idx++;
        }
        return ans;
    }
};
