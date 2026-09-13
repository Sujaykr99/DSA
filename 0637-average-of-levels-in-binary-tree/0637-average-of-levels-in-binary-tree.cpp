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
    void solve(TreeNode* root, int level, vector<vector<int>>& temp) {

        if (root == NULL)
            return;

        if (level == temp.size()) {
            temp.push_back({});
        }
        temp[level].push_back(root->val);

        solve(root->left, level + 1, temp);
        solve(root->right, level + 1, temp);
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {

        vector<vector<int>> temp;
        solve(root, 0, temp);

        vector<double> ans;

        for (int i = 0; i < temp.size(); i++) {

            int n = temp[i].size();
            long long sum = 0;

            for (int j = 0; j < temp[i].size(); j++) {

                sum += temp[i][j];
            }

            double avg = (double)sum / n;

            ans.push_back(avg);
        }
        return ans;
    }
};