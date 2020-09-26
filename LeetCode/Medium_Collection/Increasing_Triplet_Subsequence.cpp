/*
Given an unsorted array return whether an increasing subsequence of length 3 exists 
or not in the array.
Formally the function should:
    Return true if there exists i, j, k
    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        int n1 =INT_MAX, n2 = INT_MAX ;
        for(auto x : nums){
            
            if( x <= n1){    // Candidate for first number, smallest so far
                n1 = x ; 
            }     
            
            else if( x <= n2){    // Candidate for mid element
                n2 = x ;
            }            
            else {
                return true;     // n1 and n2 already in place and it larger than both of them . 
            }
        }
        
        return false;
        
    }
};