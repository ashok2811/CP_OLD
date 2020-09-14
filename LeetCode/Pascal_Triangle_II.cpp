/*
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.

Notice that the row index starts from 0.
*/

class Solution {
public:
    int nCr(int n , int r){
        long long res = 1 ;
        for(int i = 0 ; i< r ; i++){
            res *=(long long)(n-i);
            res /=(long long)(i+1);
        }
        return (int)res;
    }
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans;
        for(int i = 0 ; i <= rowIndex ; i++){
            ans.push_back(nCr(rowIndex , i));
        }
         return ans;
    }
   
};