/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Follow up: Recursive solution is trivial, could you do it iteratively?


*/


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
    void inorder(vector<int> &v , TreeNode* root){
        if(root == NULL) return;
        else{
            inorder(v, root->left);
            v.push_back(root->val);
            inorder(v, root->right);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            inorder(ans,root);
        return ans;
    }
};