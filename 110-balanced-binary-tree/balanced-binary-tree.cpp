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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0 ; 
        int left = maxDepth(root->left) ; 
        int right = maxDepth(root->right) ; 
        return max(1+ left, 1 +right) ; 
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true ;
        int right = maxDepth(root->right) ;
        int left = maxDepth(root->left) ; 
        if(left < right) left+=1; 
        if(left > right) left-=1; 
        bool cleft = isBalanced(root->left) ;
        bool cright = isBalanced(root->right) ; 
        if(left != right) return false;
        if(left == right && cleft && cright) return true ;
        return false; 
    }
};