/**
Write a program to count the number of days between two dates.

The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.

1. Calculate the no of days for years from y1 to y2(exclusive)
2. Subtract months starting from 1 to m1(exclusive), these months are unwanted as its not part of question.
3. Add months from 1 to m2(exclusive), these months are required.
4. Finally subtract the two days and the number of days.

**/
class Solution {
public:
    int daysBetweenDates(string d1, string d2) {
        vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        if(d1 > d2) 
            swap(d1, d2);
        
        int y1 = stoi(d1.substr(0, 4)), m1 = stoi(d1.substr(5, 2)), dd1 = stoi(d1.substr(8, 2));
        int y2 = stoi(d2.substr(0, 4)), m2 = stoi(d2.substr(5, 2)), dd2 = stoi(d2.substr(8, 2));
        
        int res = 0;
        for(int y = y1; y < y2; y++) res += isLeap(y) ? 366 : 365;
        for(int m = 1; m < m1; m++) res -= m == 2 ? (isLeap(y1) ? 29 : 28) : months[m];
        for(int m = 1; m < m2; m++) res += m == 2 ? (isLeap(y2) ? 29 : 28) : months[m];
        return res + dd2 - dd1;
    }
    
    bool isLeap(int y) {
        return y % 100  == 0 ? y % 400 == 0 : y % 4 == 0;
    }
};
