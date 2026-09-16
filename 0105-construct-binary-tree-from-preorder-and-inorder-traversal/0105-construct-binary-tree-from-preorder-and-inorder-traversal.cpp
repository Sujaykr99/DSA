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

 /*
    public:
        int findPosition(vector<int> inorder, int element, int n) {

            for (int i = 0; i < n; i++) {
                if (inorder[i] == element) {
                    return i;
                }
            }
            return -1;
        }
        solve{
       // int position = findPosition(inorder, ele, n); time complexity = O(N2) ;
        }
        */

class Solution {
 

    unordered_map<int, int> pos;

public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index,
                    int inorderStart, int inorderEnd, int n) {

        // base case

        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        int element = preorder[index++];

        TreeNode* root = new TreeNode(element);
        // use mapping
        int position = pos[element];
        // recursive call

        root->left =
            solve(preorder, inorder, index, inorderStart, position - 1, n);
        root->right =
            solve(preorder, inorder, index, position + 1, inorderEnd, n);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preorderIndex = 0;
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
        // store index of inorder in mapp to find position
           pos[inorder[i]] = i;
        }
        TreeNode* ans = solve(preorder, inorder, preorderIndex, 0, n - 1, n);

        return ans;
    }
};