/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.

stringstream - it acts like a cin so whenever we read into a variable, the input is read until it finds a value that is convertible to the variable type and the cursor stops when it sees a different variable.

*/


class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
};
