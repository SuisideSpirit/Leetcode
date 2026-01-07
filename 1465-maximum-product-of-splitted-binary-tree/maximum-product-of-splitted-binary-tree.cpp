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
    int maxi ;
    int MOD ;
    int sumTree(TreeNode* root , vector <int>&rootVal , vector <int>&leftTree, vector <int>&rightTree){
        if(root == NULL ) return 0 ; 

        int left = sumTree(root->left , rootVal , leftTree , rightTree) ;
        int right = sumTree(root->right , rootVal , leftTree , rightTree) ;

        rootVal.push_back(root->val) ; 
        leftTree.push_back(left) ; 
        rightTree.push_back(right) ; 

        return root->val + left + right ; 
    }
    int maxProduct(TreeNode* root) {
        vector <int> left ,right ,rt ;
        int MOD = 1000000007 ;
        long long tot = sumTree(root,rt,left,right) ; 

        int n = rt.size() ; 

        long long maxi = 0 ;

        for(int i =0 ; i<n ;i++){
            long long leftPro = (left[i])*(tot -left[i]) ;
            long long rightPro = (right[i])*(tot -right[i]) ;
            maxi = max(maxi,max(leftPro,rightPro)) ;
        }
        return maxi%MOD ;
    }
};