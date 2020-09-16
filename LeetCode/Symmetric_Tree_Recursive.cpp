// Symmetric Tree -> Leetcode
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

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
        
    bool isSymmetric(TreeNode* root) {
        
    return isMirror(root , root);
    }
    
    bool isMirror(TreeNode* root1 , TreeNode* root2){
        if(root1==NULL && root2 == NULL) return true;
        if(root1==NULL || root2==NULL)  return false;
        
        return (root1-> val == root2 -> val) &&
            isMirror(root1->left , root2->right) &&
            isMirror(root2->left , root1->right);
    }
};