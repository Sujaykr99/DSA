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
    TreeNode* createParentMapping(TreeNode* root, int target,
                                  map<TreeNode*, TreeNode*>& nodeToParent) {

        TreeNode* result = NULL;

        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty()) {

            TreeNode* front = q.front();
            q.pop();

            if (front->val == target) {
                result = front;
            }

            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return result;
    }

public:
    int infected(TreeNode* root, map<TreeNode*, TreeNode*>& nodeToParent) {

        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(root);
        visited[root] = true;

        int ans = 0;
        while (!q.empty()) {

            bool flag = false;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if (front->right && !visited[front->right]) {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = 1;
                }

                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if (flag == true) { // addition in queue / NOT
                ans++;
            }
        }

        return ans;
    }

public:
    int amountOfTime(TreeNode* root, int start) {

        map<TreeNode*, TreeNode*> nodeToParent;
        
TreeNode* targetnode = createParentMapping(root, start, nodeToParent);

        int ans = infected(targetnode, nodeToParent);

        return ans;
    }
};