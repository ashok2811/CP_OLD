/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231. 

*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y ;
        int count = 0 ;
        while(ans>0){
            count++;
            ans = ans&(ans-1);
        }
        
        return count;
    }
};