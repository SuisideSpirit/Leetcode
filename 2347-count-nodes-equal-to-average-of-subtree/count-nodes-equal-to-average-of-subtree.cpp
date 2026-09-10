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
    int ans ;
    int childNum(TreeNode* root){
        if (root == NULL) return 0 ; 
        int left = childNum(root->left); 
        int right = childNum(root->right) ;
        return left + right + 1 ;
    }
    int traversal(TreeNode* root ){
        if (root == NULL) return 0 ;
        int left = traversal(root->left) ; 
        int right = traversal(root->right) ;
        int avg = left + right + root->val ; 
        int child = childNum(root);
        if (avg/child == root-> val) ans++; 
        return avg ; 
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0 ;
        traversal(root) ;
        return ans ; 
        
    }
};