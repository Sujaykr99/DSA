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

 /* for 2 Child 
     // or we can also do this
        Node* replace = root->right;
        while(replace->left != NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deletefromBST(root->right, replace->data);
        delete replace;
        return root;
    }*/

class Solution {
private:
  TreeNode * minValue(TreeNode* root){
     TreeNode* temp = root ;
     while(temp->left!=NULL){
        temp = temp->left ;
     }
     return temp ; 

  };
  
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
         // base case
    if (root == NULL)
    {
        return root;
    }
    if(root->val == key){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        if(root->left != NULL && root->right == NULL){
            //left child
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            //right child
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->val;
            root->val = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if(root->val > key){
        // left part
        root->left = deleteNode(root->left, key);
        return root;
    }
    else{
        // right part
        root->right = deleteNode(root->right, key);
        return root;
    }
       return root; 
    }
};