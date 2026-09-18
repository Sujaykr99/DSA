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
   bool solve( TreeNode*leftnode , TreeNode *rightnode){
          
          if(rightnode==NULL&&leftnode==NULL) return true ;

          if(leftnode==NULL||rightnode==NULL) return false ;

          if(leftnode->val!=rightnode->val) return false ;

         bool inner = solve(leftnode->left , rightnode->right) ;
         bool outer = solve(leftnode->right , rightnode->left) ;
         
        return inner&&outer ;
   }
public:
    bool isSymmetric(TreeNode* root) {
       
       if(root==NULL) return true ;

       return solve(root->left , root->right) ;
         
    }
};