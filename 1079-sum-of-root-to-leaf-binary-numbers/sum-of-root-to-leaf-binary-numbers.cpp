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
    int ans = 0;
    int to_binary(string s){
        int n = s.length() ; 
        int res = 0 ;
        int mult = 1 ;
        for(int i = n-1 ; i>=0 ; i--){
            if(s[i] != '0')res += mult ;
            mult *= 2 ;
        }
        cout<<s<<" "<<res<<endl;
        return res ;
    }
    void solve(TreeNode* root , string s){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL ){
            s = s + to_string(root->val) ;
            ans += to_binary(s) ;
            return ; 
        }
        s = s + to_string(root->val) ;
        solve(root->left,s) ;
        solve(root->right,s) ; 
    }
    int sumRootToLeaf(TreeNode* root) {
        solve(root,"") ;
        return ans ;
    }
};