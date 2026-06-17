class Solution {
public:
    void height(TreeNode* root , int h , vector <vector<int>>&ans){
        if(!root) return ; 
        if(ans.size() == h){
            ans.push_back({root->val}) ; 
        }
        else ans[h].push_back(root->val) ; 

        height(root->left , h +1 ,ans) ; 
        height(root->right ,h + 1,ans) ; 
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector<int>> ans ;
        height(root,0,ans) ; 
        for(int i = 0 ; i < ans.size() ; i++){
            cout<<ans[i][0]<<endl;
            if(i%2 != 0 ){
                reverse(ans[i].begin(),ans[i].end()) ; 
            }
        }
        return ans; 

        
    }
};