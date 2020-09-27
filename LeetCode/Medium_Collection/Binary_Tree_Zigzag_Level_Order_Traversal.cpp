/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

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
    
void LevelOrder(TreeNode* root, vector<vector<int>>& ans){
      if(root == NULL) return;
        queue<TreeNode*> Q;
        Q.push(root);        
        
        bool flag =1 ;
    
        while(!Q.empty()){
            int size = Q.size();
            vector<int> ans1(size);
            
            for(int i = 0 ; i< size; i++){
                TreeNode* current = Q.front();
                Q.pop();               
                
                if(flag==1) ans1[i] = current-> val; // FWD fill ;     
                if(flag==0) ans1[size-i-1] = current-> val;  // Rev Fill                
                
                if(current -> left != NULL)                  
                     Q.push(current->left);
                if(current -> right != NULL)                    
                    Q.push(current->right);            
            }
            
            flag = !flag;   // Change Flag for next be fill as rev to current                   
            ans.push_back(ans1);     // Push the current elements    
        }
       
}
    
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {    
        vector<vector<int>> ans;
        LevelOrder(root, ans);        
        return ans;
    }
};