/*
Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.
Follow up: Could you write a solution that works in logarithmic time complexity?
*/

// log5(N) solution

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n>0){
            n = n/5;
            ans+=n;
        }        
        return ans;
    }
};