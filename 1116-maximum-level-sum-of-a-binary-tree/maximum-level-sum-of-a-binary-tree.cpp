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
    void Traversal(vector <long long> &v , TreeNode* root ,int level){
        if(root == NULL ) return ;
        if(v.size() < level) v.push_back(root->val) ; 
        else v[level-1] += root->val ; 

        Traversal(v , root->left , level + 1) ; 
        Traversal(v, root->right , level + 1) ; 
    }
    int maxLevelSum(TreeNode* root) { 
        vector <long long> v ; 
        Traversal(v,root, 1) ; 

        int maxi = -INT_MAX ;
        int minL = 1 ;
        for(int i = 0 ; i<v.size() ; i++){
            if(v[i] > maxi){
                minL= i ;
                maxi = v[i] ;
            }
            cout<<v[i]<<" "<<maxi<<endl;
        }
        return minL+1; 

        
    }
};