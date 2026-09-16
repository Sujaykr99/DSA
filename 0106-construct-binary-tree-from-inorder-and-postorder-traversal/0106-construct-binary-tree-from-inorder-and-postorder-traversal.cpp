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
    unordered_map<int, int> pos;

public:
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& index,
                    int inorderStart, int inorderEnd, int n) {

        // base case

        if (index < 0 || inorderStart > inorderEnd) {
            return NULL;
        }
        int element = postorder[index--];

        TreeNode* root = new TreeNode(element);
        // use mapping
        int position = pos[element];
        // recursive call
        
         root->right =
            solve(postorder, inorder, index, position + 1, inorderEnd, n);

        root->left =
            solve(postorder, inorder, index, inorderStart, position - 1, n);
       
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();
        int postorderIndex = n - 1;

        for (int i = 0; i < n; i++) {
            // store index of inorder in mapp to find position
            pos[inorder[i]] = i;
        }
        TreeNode* ans = solve(postorder, inorder, postorderIndex, 0, n - 1, n);

        return ans;
    }
};