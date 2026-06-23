/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool check(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return false ;
        if(root == p || root == q) return true ;
        bool left = check(root->left,p,q) ; 
        bool right = check(root->right,p,q) ; 
        return left || right ; 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL ; 
        if(root == p || root == q) return root ; 
        
        bool left = check(root->left , p , q ) ;
        bool right = check(root->right , p , q ) ; 
        
        if(left == 1 && right == 1 ) return root; 
        
        if(left == 1) return lowestCommonAncestor(root->left, p, q) ;
        else return lowestCommonAncestor(root->right, p, q) ;

    }
};