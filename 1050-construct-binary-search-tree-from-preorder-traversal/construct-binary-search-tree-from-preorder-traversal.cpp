class Solution {
public:
    int search(int start , int end ,int target , vector <int> &v){
        for(int i = start ; i <= end ; i++){
            if(v[i] >= target) return i ;
        }
        return end+1 ;
    }
    TreeNode* build(int start , int end ,vector<int>& v){
        if(start > end) return NULL ; 
        TreeNode* root = new TreeNode(v[start]) ; 
        int mid = search(start+ 1, end , v[start] , v) ; 
        root->left = build(start + 1 , mid -1 , v) ; 
        root->right = build(mid, end , v) ; 
        return root ; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size() ; 
        return build(0 , n -1 , preorder ) ; 
    }
};