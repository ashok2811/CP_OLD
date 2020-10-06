/*
Given preorder and inorder traversal of a tree, 
construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7
*/

class Solution {
    unordered_map<int, int> mp;
    int preIndex = 0;
    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder , int start, int end){
            if(start > end) return NULL;
        
            TreeNode* root = new TreeNode(preorder[preIndex++]);
            
            if(root==NULL) return NULL; 
            if(start==end) return root;
        
            int idx = mp[root->val] ;
        root-> left = makeTree(preorder, inorder, start , idx -1);
        root-> right = makeTree(preorder, inorder, idx+1 ,  end);
        
        return root;
        
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0 ; i< n ; i++){
            mp[inorder[i]] = i ;
        }
        
        return makeTree(preorder, inorder, 0 , n-1);
    }
};


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