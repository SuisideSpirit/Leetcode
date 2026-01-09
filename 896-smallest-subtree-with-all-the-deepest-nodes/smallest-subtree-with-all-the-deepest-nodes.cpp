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
    int maxDepth ;
    void depth(TreeNode* root,int D,vector<int>&Depth,vector <TreeNode*>& node){
        if(root == NULL ) return ;
        node[root->val] = root ; 
        depth(root->left,D+1,Depth,node) ;
        depth(root->right,D+1,Depth,node) ; 
        Depth[root->val] = D;
        maxDepth = max(maxDepth,Depth[root->val]) ;
        return ;
    }
    int Traversal(TreeNode* root,vector <int>& below,vector<int> &Depth){
        if(root == NULL) return 0 ; 
        if(Depth[root->val] == maxDepth) return below[root->val] = 1 ; 
        
        int left = Traversal(root->left , below , Depth) ;
        int right = Traversal(root->right,below , Depth) ; 
        below[root->val] = left + right ; 

        return below[root->val] ; 
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector <int> Depth(505 , 0) ; 
        vector <int> below(505 , 0 ) ; 
        vector <TreeNode*> node(505) ;
        maxDepth = 0 ; 

        depth(root,1, Depth , node) ; 
        Traversal(root, below, Depth) ;
        int maxi = 0 ; 
        int maxD = 0 ;
        int ans = 0 ; 
        for(int i =0; i<=500 ; i++){
            //cout<<i<<" "<<below[i]<<" "<<Depth[i]<<endl;
            if(below[i] > maxi){
                ans = i ; 
                maxD = Depth[i] ; 
                maxi = below[i] ;
            }
            if(below[i] == maxi && maxD < Depth[i]){
                ans = i ; 
                maxD = Depth[i] ;
            }
        }
        cout<<ans<<endl;
        return node[ans] ;
    }
}; 