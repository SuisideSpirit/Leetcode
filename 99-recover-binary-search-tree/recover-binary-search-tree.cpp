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
    int idx1 = -1, idx2 = -1 ; 
    TreeNode* n1 = NULL; 
    TreeNode* n2 = NULL; 
    int idx = 0 ; 
    void Traversal(TreeNode* root ,vector <int>& v){
        if(!root) return ;
        Traversal(root->left , v); 
        v.push_back(root->val) ; 
        Traversal(root->right, v) ;
    }
    void change(TreeNode* root){
        if(!root) return ; 
        change(root->left) ; 
        idx += 1 ; 
        if(idx == idx1 +1) n1 = root ; 
        else if(idx  == idx2 +1) n2 = root ;
        change(root->right) ; 
    }
    void recoverTree(TreeNode* root) {
        vector <int> v , s; 
        Traversal(root , v) ;
        s = v ; 
        sort(s.begin() , s.end()) ; 
        for(int i = 0; i < v.size(); i++ ){
            if(v[i] != s[i]){
                if(idx1 == -1) idx1 = i ;
                else idx2 = i ; 
            }
        }
        idx = 0 ; 
        change(root) ; 
        swap(n1->val, n2->val);
    }
};