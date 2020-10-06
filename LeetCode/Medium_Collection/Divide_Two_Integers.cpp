/*
Divide Two Integers

Given two integers dividend and divisor, divide two integers without 
using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing 
its fractional part. For example, truncate(8.345) = 8 and truncate
(-2.7335) = -2.

Note:

    Assume we are dealing with an environment that could only store 
    integers within the 32-bit signed integer range: [−231,  231 − 1]. 
    For this problem, assume that your function returns 231 − 1 when 
    the division result overflows.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};