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

                          // BFS+Reverse
 /* class Solution {
    public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> temp(size); // if temp->size = out of bound

            for (int i = 0; i < size; i++) {

                TreeNode* frontNode = q.front();
                q.pop();

                int idx = i;  // kon se level pe hai 
                temp[idx] = frontNode->val; // val temp mai daal do i idx

                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};*/
   

class Solution {
public:
    void solve(TreeNode* root , int level , vector<vector<int>>& ans){

        if(root==NULL) return ;

        if(level==ans.size()){

            ans.push_back({}) ;
        }

        ans[level].push_back(root->val) ;

        solve(root->left , level+1 , ans) ;
        solve(root->right , level+1 , ans ) ;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> ans ;

        solve(root , 0 , ans) ;

         reverse(ans.begin(), ans.end());

        return ans;

        
        
    }
};