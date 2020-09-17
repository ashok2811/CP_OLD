// Binary Tree Level Order Traversal

// Given a binary tree, return the level order traversal 
//of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its level order traversal as:

// [
//   [3],
//   [9,20],
//   [15,7]
// ]


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) { return {}; }
        vector<vector<int>> ans;
        vector<int> ans1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int child = 1 ;
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();   

            if(temp->left !=NULL){
                q.push(temp->left);
             
            }
            
            if(temp->right !=NULL){
                q.push(temp->right);
            }
            
           ans1.push_back(temp->val);             
            if(--child == 0){
                ans.push_back(ans1);
                ans1.clear();
                child=q.size();
            }

            
        }
        
        return ans;
        
    }
};