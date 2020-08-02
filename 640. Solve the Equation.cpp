/*
Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.


*/
class Solution {
public:
    string solveEquation(string equation) {
        int i =0;
        int para=0, xpara=0; // x parts and constant parts
        int flag = 1;
        while(i<equation.size())
        {
            int sign = 1;
            int temp = 0;
            if(equation[i] == '=') // change the flag as we bring right-side equation to left so change sign which is flag.
            {
                flag = -1;
                i++;
            }
            if(equation[i] == '-')
            {
                sign = -1;
                i++;
            }
            if(equation[i] == '+')
            {
                sign = 1;
                i++;
            }
            
            if(isdigit(equation[i]))
            {
                while(i<equation.size() && isdigit(equation[i])) // n-digit number so we loop and form a number.
                {
                    temp = temp*10 + equation[i]-'0';
                    i++;
                }
                if(i< equation.size() && equation[i] == 'x') //  If it is x then add it to x part
                {
                    xpara += flag*sign*temp;
                    i++;
                }
                else // If it is constant part, then add it to constant part
                    para += flag*sign*temp;
            }
            else //x
            {
                xpara += flag*sign;
                i++;
            }
            
        }
        string res;
        //cout<<para<<", "<<xpara<<endl;
        if(para == 0 && xpara == 0) // No constant part and No x part so return Infinite solutions.
            res = "Infinite solutions";
        else if(xpara == 0) //  If only x part is null then no solution
            res = "No solution";
        else
            res = "x="+to_string(para/xpara*-1); // prepare the answer if all exists.
        return res;
    }
};
