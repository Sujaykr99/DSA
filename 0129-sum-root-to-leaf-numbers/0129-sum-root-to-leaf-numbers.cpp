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
    void solve(TreeNode* root, string path, int& sum) {

        if (root == NULL)
            return;

        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {

            sum += stoi(path);
        }

        solve(root->left, path, sum);
        solve(root->right, path, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        string path = "";
        int sum = 0;
        solve(root, path, sum);

        return sum;
    }
};