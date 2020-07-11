/*
https://leetcode.com/problems/super-pow/discuss/84534/1-liners-and-other-with-explanations
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
*/

class Solution(object):
    def superPow(self, a, b):
         return pow(a, int(''.join(map(str, b))), 1337)
        
