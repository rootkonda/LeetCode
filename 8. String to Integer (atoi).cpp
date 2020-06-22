/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.


I think we only need to handle four cases:

discards all leading whitespaces
sign of the number
overflow
invalid input

*/
class Solution {
public:
    int myAtoi(string str) 
    {
        bool neg = false;
        int num=0;
        int i=0;
        while(str[i]==' ') // To skip the initial whitespaces
            i++;
        if(str[i]=='-' or str[i]=='+') // if first non-whitespace character is +/- then set a falg and go to next character.
        {
            if(str[i]=='-')
                neg=true;
            i++;
        }
        
        while(str[i]>='0' and str[i]<='9') // If first character after +/- should be digit to continue or else just return num based on sign
        {
            if(num > INT_MAX/10 or (num==INT_MAX/10 and str[i]-'0'>7)) // INT_MAX/10 is to check if the number so far is bigger than or equal to INT_MAX.
            if its bigger or equal then we have to return INT_MAX or INT_MIN. This is a method to use without long long and to check overflow of integers
                return (neg ? INT_MIN : INT_MAX);
            num = num*10 + (str[i++]-'0');
        }
        return (neg ? -num : num);
    }
};
/*
"words and 987"
"4193 with words"
"   -42"
"42"
"-91283472332"
"91283472332"
"3.14159"
".1"
"+-2"
*/
