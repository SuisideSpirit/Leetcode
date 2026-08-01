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
    TreeNode* solve(int postidx  , int st , int end ,vector<int>& inorder, vector<int>& post){
        if(end < st) return NULL ; 
        int root = post[postidx] ;
        TreeNode* tree = new TreeNode(root) ;
        cout<<postidx<<" "<<st<<" "<<end<<endl;
        if(st == end) return tree ; 

        int idx = end ; 
        int count = 0 ; 
        for(int i = st ; i <= end ; i++){
            if(inorder[i] == root){
                idx = i ; 
                break ; 
            }
        }
        tree->left = solve(postidx - (end - idx + 1) ,st , idx -1  , inorder , post) ; 
        tree->right = solve(postidx -1 ,idx +1 ,end , inorder , post) ; 

        return tree ; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() ; 
        return solve(n-1 , 0 , n-1 , inorder ,postorder) ; 
    }
};