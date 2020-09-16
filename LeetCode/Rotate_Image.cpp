// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
//  DO NOT allocate another 2D matrix and do the rotation.


//Method 1

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        int a = 0 ;
        int b =n-1;
        
        while(a<b){
            for(int i = 0 ; i < b-a; i++){
                swap(matrix[a][a+i] , matrix[a+i][b]);
                swap(matrix[a][a+i] , matrix[b][b-i]);
                swap(matrix[a][a+i] , matrix[b-i][a]);
            }
            a++;
            b--;
        }
        
    }
};


// Method 2

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int i = 0 ; i< n ; i++){  // Transpose
            for(int j = 0 ; j< i; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        
        for(int i =0 ; i< n ; i++ ){   // reverse
            reverse(matrix[i].begin() , matrix[i].end());
        }