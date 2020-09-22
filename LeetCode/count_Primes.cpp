class Solution {
public:
    
    bool isPrime(int n){
      if(n == 2 || n==3){
            return 1;
        }
        else{
            for(int i =2 ; i*i <= n ; i++){
                if(n%i==0){
                    return 0;
                }
            }
            return 1;
        }
    }
    int countPrimes(int n) {
        int count = 0 ;
        for(int i = 2 ; i<n ; i++){
            if(isPrime(i)) count ++;
        }
        
        return count;
    }
};