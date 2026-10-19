/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  struct Info {
        bool isbst;
        int sum;
        int minval;
        int maxval;
    };

 public : 
 Info solve(TreeNode* root, int& maxsum) {

        if (root == NULL) {
           return {true, 0, INT_MAX, INT_MIN};
        }
        Info left = solve(root->left, maxsum);
        Info right = solve(root->right, maxsum);

        if (left.isbst && right.isbst && left.maxval < root->val &&
            right.minval > root->val) {

            int sum = left.sum + root->val + right.sum;
             maxsum = max(maxsum, sum);

     return {true,sum,min(left.minval, root->val),max(right.maxval, root->val)};
        }
        return{false , 0, 0 , 0} ;
    };

public:
    int maxSumBST(TreeNode* root) {

        int maxsum = 0 ;
        solve(root , maxsum) ;
        return maxsum ;
    }
};