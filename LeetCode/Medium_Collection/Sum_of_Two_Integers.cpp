/*
Sum of Two Integers

Calculate the sum of two integers a and b, 
but you are not allowed to use the operator + and -.
*/

class Solution {
public:
    
    int add(unsigned int x, unsigned int y) { 
	unsigned int keep = (x & y) << 1;  // This Carry will be shifted towards left
	unsigned int res = x^y; 

	// If bitwise & is 0, then there 
	// is not going to be any carry. 
	// Hence result of XOR is addition. 
	if (keep == 0) 
		return res;         
	return add(keep, res); 
} 
    
    

    int getSum(int a, int b) {
        
        return add(a , b);
        
    }
};

/* Full Adder
3 : 0011
5 : 0101
    
  : 0010  & AND << 1 
  : 0110  ^
      
  : 0100  & AND << 1
  : 0100  ^
  
  : 1000  & AND << 1
  : 0000  ^
      
  : 0000  & AND << 1  Base condition
  : 1000   >> Ans : 8 
*/      