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
    TreeNode* start ; 
    void Traversal(TreeNode * root ,TreeNode* target, vector <TreeNode*>& parent){
        if(!root) return ; 
        if(root->val == target->val) start = root; 
        if(root->left != NULL){
            parent[root->left->val] = root; 
        }
        if(root->right != NULL){
            parent[root->right->val] = root; 
        }
        Traversal(root->left , target , parent) ; 
        Traversal(root->right , target , parent) ; 
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector <TreeNode*> parent(500, NULL) ; 
        Traversal(root, target ,parent) ; 
        vector <int> visited(500,0) ; 
        queue <TreeNode*> q ;
        q.push(start) ; 
        int dist = 0 ;
        vector <int> ans ;
        visited[start->val] = 1 ;
        while(q.size() != 0 ){
            if(dist == k){
                while(q.size() != 0){
                    auto ele = q.front() ;
                    ans.push_back(ele->val) ; 
                    q.pop() ; 
                }
                break; 
            }
            dist++; 
            int size = q.size() ;
            for(int i = 0 ; i < size ;i++){
                auto ele = q.front() ;
                q.pop() ;  
                if(ele->left != NULL && visited[ele->left->val] == 0){
                    visited[ele->left->val] = 1;
                    q.push(ele->left) ; 
                } 
                if(ele->right != NULL && visited[ele->right->val] != 1){
                    visited[ele->right->val] = 1;
                    q.push(ele->right) ; 
                }
                if(parent[ele->val] != NULL){
                    TreeNode* par = parent[ele->val] ; 
                    if(visited[par->val] == 0){
                        visited[par->val] = 1 ;
                        q.push(par) ;
                    }
                }
            }

        }
        return ans ;

        
    }
};