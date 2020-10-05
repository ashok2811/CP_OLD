/*
Given a column title as appear in an Excel sheet, 
return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
    int multi(int n){
        int ans =1;
        for(int i = 0 ; i <n-1 ;i++) ans*=26;        
        return ans;
    }
public:
    int titleToNumber(string s) {
        int n = s.length();
        int ans = 0;
        for(auto x : s){
            ans = ans + (int)(x-'A'+1)*multi(n);
            n--;
        }
       return ans; 
    }
};