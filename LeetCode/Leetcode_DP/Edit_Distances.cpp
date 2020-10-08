// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

// You have the following 3 operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3

class Solution {
public:
    
    
    int editDis(string word1, string word2 , int i , int j, vector< vector< int>> &dp ){
        // Base cases
       
        // Case 1:  if i finished
        if(i <0) return j+1 ;
        
        // Case 2:  if j finished
        if(j<0) return i+1 ;
        
        // Using Memoization
        if(dp[i][j] != -1) return dp[i][j]; 
        
        // Case 3: Both are matching
        if(word1[i]== word2[j])
            return dp[i][j] = editDis(word1 , word2, i-1, j-1, dp) ;
        
        // Case 4: Both are not matching
         else{
             int insert = 1 + editDis(word1 , word2, i, j-1, dp);
             int remove = 1 + editDis(word1 , word2, i-1, j, dp);
             int replace = 1 + editDis(word1 , word2, i-1, j-1, dp);
             
             // Return Min of these two
             return dp[i][j] = min(insert, min(remove, replace)); 
         }
        
        
        
    }
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        vector< vector< int> > dp(n , vector<int>(m, -1)); // fill all with -1 
        return editDis(word1, word2, n-1 , m-1 , dp);
    }
};