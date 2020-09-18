/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* BST(vector<int> & nums ,  int L , int R){
        if(L>R){return NULL ;}
        else{
            int mid = L + (R-L)/2;
        TreeNode * child = new TreeNode(nums[mid]);
        child->left = BST(nums,  L , mid-1);
        child->right = BST(nums, mid+1 , R);
        return child;
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
            int n = nums.size();
            return BST(nums, 0 , n-1);
        
    }
};