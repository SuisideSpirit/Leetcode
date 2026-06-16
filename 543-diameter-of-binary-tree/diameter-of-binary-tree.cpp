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
    int depth(TreeNode* root){
        if(root == NULL ) return 0 ; 
        return 1 + max(depth(root->left) , depth(root->right)) ; 
    }
    int dia(TreeNode* root){
        if(root == NULL ) return 0 ; 
        int h1 =  depth(root->left) ; 
        int h2 = depth(root->right) ; 
        int ans = dia(root->left) ; 
        ans =max(ans,dia(root->right)) ; 
        ans = max(h1 + h2 , ans ); 
        return ans ; 

    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root) ; 
    }
}; 