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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue <TreeNode*> q; 
        vector <vector <int>> ans ; 
        if(!root) return ans ;
        q.push(root) ;
        while(q.size() != 0 ){
            int size = q.size() ;
            vector <int> temp ; 
            while(size--){
                auto ele = q.front() ; 
                q.pop() ; 
                temp.push_back(ele->val) ; 
                if(ele->left) q.push(ele->left) ; 
                if(ele->right) q.push(ele->right) ; 
            }
            ans.push_back(temp) ; 
        }
        for(int i = 0 ; i < ans.size()/2 ; i++){
            swap(ans[i] , ans[ans.size()-1-i]) ; 
        }
        return ans ; 
        
    }
};