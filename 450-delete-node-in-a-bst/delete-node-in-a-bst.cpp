class Solution {
public:
    void Change(TreeNode* root,int key){
        TreeNode* target ; 
        if(root->left != NULL && root->left->val == key){
            target = root->left ; 
            if(target->left == NULL && target->right == NULL ) root->left = target->right ;
            else if(target->left == NULL ) root->left = target->right ;
            else if(target->right == NULL ) root->left = target->left ;
            else{
                TreeNode* temp = target->left ; 
                while(temp->right != NULL) temp = temp->right ; 
                temp->right = target->right ; 
                root->left = target->left ;
            }
        }
        else{
            target = root->right ;
            if(target->left == NULL && target->right == NULL ) root->right = target->right ;
            else if(target->left == NULL ) root->right = target->right ;
            else if(target->right == NULL ) root->right = target->left ;
            else{
                TreeNode* temp = target->left ; 
                while(temp->right != NULL) temp = temp->right ; 
                temp->right = target->right ; 
                root->right = target->left ;
            }
        }  
    }
    void Traversal(TreeNode* root , int key){
        if(!root) return ;
        if(root->left != NULL &&root->left->val == key)Change(root , key)  ;
        else if(root->right != NULL && root->right->val == key)Change(root , key)  ;

        Traversal(root->left , key) ; 
        Traversal(root->right , key)  ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = new TreeNode(1) ; 
        temp->left = root ; 
        Traversal(temp,key) ; 
        return temp->left ; 
    }
};