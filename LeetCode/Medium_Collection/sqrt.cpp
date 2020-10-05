/*
Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed 
to be a non-negative integer.

Since the return type is an integer, the decimal digits are 
truncated and only the integer part of the result is returned.
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int ans = 0 ;
        for(long long i = 1 ; i*i <=x; i++){
            ans++;
        }
        
        return ans;
    }
};