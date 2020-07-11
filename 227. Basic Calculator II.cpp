/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.


*/

 class Solution {
  public:
      int calculate(string s) {
        stringstream ss("+" + s); // since we take two characters at a time, the first character doesnt have any sign with it.
        char op;
        int n, last, ans = 0;
        while (ss >> op >> n) { // Read two characters at a time, operator first and then number second.
            if (op == '+' || op == '-') { // n has latest digit i.e. right number
                n = op == '+' ? n : -n;
                ans += n; // always add it to the answer
            } else {
                n = op == '*' ? last * n : last / n;
                ans = ans - last + n; // since answer has left digit so subtract it to avoid double counting.
            }
            last = n; // last has the left number
        }
        return ans;
      }
  };
