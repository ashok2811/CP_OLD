/*
 Maximum Sum Obtained of Any Permutation

 We have an array of integers, nums, and an array of requests where
  requests[i] = [starti, endi]. The ith request asks for the sum of
   nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi].
   Both starti and endi are 0-indexed.

Return the maximum total sum of all requests among all permutations of nums.

Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
Output: 19
Explanation: One permutation of nums is [2,1,3,4,5] with the following result: 
requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
Total sum: 8 + 3 = 11.
A permutation with a higher total sum is [3,5,4,2,1] with the following result:
requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
Total sum: 11 + 8 = 19, which is the best that you can do.
*/

class Solution {
public:
    int maxSumRangeQuery(vector<int>& a, vector<vector<int>>& requests) {
        int n = a.size();
        vector<int> cnt(n); 
        for(auto req : requests){
            int L = req[0] , R = req[1];
            cnt[L]++ ;
            if(R!=n-1){cnt[R+1]--;}
            
            // for(int i = L ; i<=R; ++i){
            //     ++cnt[i];
            // }
        }
        
        for(int i = 1; i<n; i++){
            cnt[i] += cnt[i-1];
        }
        
        sort(cnt.begin(), cnt.end());
        sort(a.begin(), a.end());
        
        const int mod = 1e9+7 ;
        int answer = 0;
        for(int i = 0 ; i<n; ++i){
            answer = (answer +  (long long)a[i]*cnt[i]) %mod;
        } 
        
        return answer;
        
    }
};