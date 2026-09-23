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
    int solve(TreeNode* root, int& sum) {

        if (root == NULL)
            return 0;

        int leftSum = solve(root->left, sum);
        int rightSum = solve(root->right, sum);

        sum += abs(leftSum - rightSum);

        return root->val + leftSum + rightSum;
    }

public:
    int findTilt(TreeNode* root) {

        int sum = 0;

        solve(root, sum);
        return sum;
    }
};