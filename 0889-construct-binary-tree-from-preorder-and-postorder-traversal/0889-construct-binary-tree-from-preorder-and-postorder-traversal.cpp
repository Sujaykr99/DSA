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
class Solution {
    
    unordered_map<int, int> pos;

public: 
  TreeNode * solve(vector<int>& preorder, vector<int>& postorder , int &index ,
                            int postorderstart , int postorderend){

        if(index>=preorder.size() || postorderstart>postorderend) return NULL ;

        int element = preorder[index++] ;

        TreeNode * root = new TreeNode(element) ;

        if (postorderstart == postorderend) {
            return root;
        }
         // leftroot = preorder : root->next element 
        int leftroot = preorder[index] ;
        // find leftroot in postorder 
        int position = pos[leftroot];

        // Left subtree
        root->left = solve(preorder, postorder, index,
                           postorderstart, position);

        // Right subtree
        root->right = solve(preorder, postorder, index,
                            position + 1, postorderend - 1);


 return root ;
                            
 }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        int preorderindex = 0 ;
        int n = postorder.size() ;

        for(int i = 0 ; i< n ; i++){
            pos[postorder[i]] = i ;
        }
 
         TreeNode* ans = solve(preorder , postorder , preorderindex,0 , n-1) ;

         return ans ; 
        
        
    }
};