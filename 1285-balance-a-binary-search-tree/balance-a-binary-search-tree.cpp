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
    void build( TreeNode* root , vector <int> &v){
        if(root == NULL) return ; 
        build(root->left,v) ; 
        v.push_back(root->val) ; 
        build(root->right , v) ;
    }
    TreeNode* tree(vector <int> &v, int s , int e ){
        if(s > e) return NULL;
        int mid = (s + e)/2 ;
        TreeNode* curr =new TreeNode(v[mid]) ;  
        TreeNode* leftN = tree(v,s,mid-1) ; 
        TreeNode* rightN = tree(v,mid +1 , e)  ;
        curr->left = leftN ;
        curr->right = rightN ;

        return curr ;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector <int> v; 
        build(root, v) ;
        return tree(v, 0 ,v.size() -1 );    
    }
};