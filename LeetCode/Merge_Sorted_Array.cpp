/* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.

Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]  */


// Key : Merger from End 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m-1 , ptr2  = n-1 , ptr3  = m +n -1 ;
        
        while(ptr1 >=0 && ptr2>=0){
            if(nums1[ptr1] > nums2[ptr2]){
                nums1[ptr3--] = nums1[ptr1--];
            }
            else{
                 nums1[ptr3--] = nums2[ptr2--];
            }
        }
        
        while(ptr2>=0){
            nums1[ptr3--] = nums2[ptr2--];
        }
        
        
        
    }
};

