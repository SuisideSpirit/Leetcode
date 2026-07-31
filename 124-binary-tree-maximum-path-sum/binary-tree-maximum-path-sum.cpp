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
    int ans = INT_MIN ; 
    int solve(TreeNode* root){
        if(!root) return 0 ; 

        int left = solve(root->right) ; 
        int right = solve(root->left) ;

        ans = max(ans , max(0,left) + max(0,right) + root->val)  ;
        int res = max(left, right) ; 
        res = max(0 , res) ; 
        res = max( 0 , res + root->val );
        return res ;
    }
    int maxPathSum(TreeNode* root) {
        solve(root) ;
        return ans ;
    }
};