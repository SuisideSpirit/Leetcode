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
public:
    int ans =0 ; 
    void solve(int val , TreeNode* root){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL){
            val = val*10 + root->val ; 
            ans += val ;
            return ;  
        }
        val = val*10 + root->val ; 
        solve(val , root->left) ; 
        solve(val , root->right) ;
    }
    int sumNumbers(TreeNode* root) {
        ans = 0 ; 
        solve(0 , root) ; 
        return ans ; 
    }
};