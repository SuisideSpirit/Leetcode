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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue <pair<TreeNode* , pair<int,int>>> q ; 
        q.push({root, {0 , 0 }}) ; 
        map <int ,map<int,multiset<int>>> mp ; 
        while(q.size() != 0 ){
            int size = q.size() ; 
            while(size--){
                auto ele = q.front()  ;
                q.pop();
                int level = ele.second.first , pos = ele.second.second; 
                TreeNode* temp = ele.first ; 
                mp[pos][level].insert(temp->val) ; 

                if(temp->left) q.push({temp->left ,{level + 1, pos -1 }}) ;
                if(temp->right) q.push({temp->right,{level + 1, pos +1 }}) ; 
            }
        }
        vector <vector<int>> ans ; 
        for(auto x :mp){
            vector <int> temp ; 
            for(auto y :x.second){
                for(auto z : y.second){
                    temp.push_back(z) ; 
                }
            }
            ans.push_back(temp)  ;
        }
        return ans ;
    }
};