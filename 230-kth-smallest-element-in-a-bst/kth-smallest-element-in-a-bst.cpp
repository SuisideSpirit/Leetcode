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
    int idx = 0 ;
    vector <int> v; 
    void Traversal(TreeNode* root){
        if(!root) return ; 
        Traversal(root->left) ; 
        v[idx] = root->val ; 
        idx++;
        Traversal(root->right) ;
    }
    int kthSmallest(TreeNode* root, int k) {
        v.resize(10005 , -1)  ;
        Traversal(root) ;
        return v[k-1] ;
    }
};