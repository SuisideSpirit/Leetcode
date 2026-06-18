class Solution {
public:
    int count = 0 ; 
    int leftmost(TreeNode * root) {
        if(!root) return 0 ; 
        return 1 + leftmost(root->left) ; 
    }
    int rightmost(TreeNode * root) {
        if(!root) return 0 ; 
        return 1 + rightmost(root->right) ; 
    }
    void Traversal(TreeNode* root){
        if(!root) return ; 
        int left = leftmost(root) ; 
        int right = rightmost(root) ; 
        if(left == right) count += (pow(2,left) - 1 );
        else{
            count += 1 ; 
            Traversal(root->left) ; 
            Traversal(root->right) ;
        }
    }
    int countNodes(TreeNode* root) {
        Traversal(root) ;
        return count ; 
        
    }
};