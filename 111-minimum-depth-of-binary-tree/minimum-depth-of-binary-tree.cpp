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
    int solve(TreeNode* root){
        if(root == NULL) return 1000000 ; 
        if(root->left == NULL && root->right == NULL) return 1 ; 

        int l = solve(root->left) +1  ; 
        int r = solve(root->right) + 1 ;

        return min(l,r) ; 
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0 ; 
        return solve(root) ; 
        
        
    }
};