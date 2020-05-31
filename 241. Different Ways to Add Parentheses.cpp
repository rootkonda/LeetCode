/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


"2*3-4*5"
For every operator(+,* and -) split it into two parts. 0 to the operator(excluding it) and rest of the string excluding the operator. Both of them are separate recursive calls. At each stage, we get a value for different combination back to the starting call. 

*/


class Solution {
public:
    vector<int> diffWaysToCompute(string input) 
    {
        vector<int> ans;
        
        for(int i=0;i<input.size();i++)
        {
            char c = input[i];
            if(ispunct(c))
            {
                for(int a : diffWaysToCompute(input.substr(0,i)))
                    for(int b : diffWaysToCompute(input.substr(i+1)))
                        ans.push_back(c=='*' ? (a*b) : c=='+' ? (a+b) : (a-b));
            }
        }
        return ans.size() ? ans : vector<int>({stoi(input)});
    }
};
