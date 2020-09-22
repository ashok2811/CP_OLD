// Roman to Integer

class Solution {
public:
    int romanToInt(string s) {
        
        map<char , int > m ; 
        m['I'] = 1 , m['V'] = 5 , m['X'] = 10 , m['L'] = 50 , m['C'] = 100 , m['D'] = 500 , m['M'] = 1000 ; 
        
        int n = s.length();
        int sum  = 0 ;
        
        for(int i = 0 ; i< n ; i++){
            sum += m[s[i]];
            if(i>0 && ( (s[i-1] == 'I' && (s[i] == 'V' ||  s[i] == 'X')) ||
                        (s[i-1] == 'X' && (s[i] == 'L' ||  s[i] == 'C')) ||
                       (s[i-1] == 'C' && (s[i] == 'D' ||  s[i] == 'M'))
              
              )){
                sum -= 2*m[s[i-1]];
            }
        }
        
        return sum;
    }
};