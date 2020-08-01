/*

Aliases L1,L2 and L3.
Check if they are consecutive id's
amd their NUM's are same.

*/
SELECT DISTINCT L1.NUM AS ConsecutiveNums FROM LOGS L1,LOGS L2, LOGS L3
WHERE   L1.ID = L2.ID-1 
AND     L2.ID = L3.ID-1
AND     L1.NUM = L2.NUM
AND     L2.NUM = L3.NUM;
