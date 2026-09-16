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
public:
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& ans,
               vector<int> temp) {

        if (root == NULL)
            return;

        temp.push_back(root->val);
        // left call
        solve(root->left, targetSum, ans,temp);
        // right call
        solve(root->right, targetSum, ans ,temp);

        if (root->left == NULL && root->right == NULL) {

            int sum = 0;
            for (int i = 0; i < temp.size(); i++) {

                sum += temp[i];
            }

            if (sum == targetSum) {
                ans.push_back(temp);
            }
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        
      vector<int>temp ;
      vector<vector<int>> ans;
      solve(root , targetSum ,ans ,temp) ;

      return ans ;

    }
};