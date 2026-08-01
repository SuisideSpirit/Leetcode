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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue <TreeNode*> q ; 
        q.push(root) ; 
        vector <vector<int>> ans;
        if(!root) return ans ;  
        bool flag = true ; 
        while(q.size() != 0){
            int size = q.size() ;
            vector <int> temp ;
            while(size--){
                TreeNode* n = q.front() ;
                q.pop() ; 
                temp.push_back(n->val) ; 
                if(n->left) q.push(n->left) ; 
                if(n->right) q.push(n->right) ; 
            }
            if(flag){
                ans.push_back(temp) ; 
            }
            else{
                reverse(temp.begin() , temp.end()) ; 
                ans.push_back(temp) ; 
            }
            flag = 1 - flag;
        }
        return ans ;
        
    }
};