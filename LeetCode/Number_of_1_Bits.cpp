// Write a function that takes an unsigned integer and return the number of '1'
// bits it has (also known as the Hamming weight).
// Input: 00000000000000000000000000001011
// Output: 3

// Key Count  number of set bits

class Solution {
    
public:
    int setbits(uint32_t n){
        int count = 0 ;
        while(n>0){
            n = n&(n-1);
            count++;
        }
        return count;
    }
    
    int hammingWeight(uint32_t n) {
    
        return setbits(n);
    }
};