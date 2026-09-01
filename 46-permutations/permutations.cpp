class Solution {
public:
    vector <vector<int>> ans ;
    void solve(vector <int> &nums , vector <int> &v , unordered_set <int> st ){
        if(st.size() == nums.size()){
            ans.push_back(v) ;  
            return ; 
        }
        for(int i = 0 ; i < nums.size() ;i++){
            if(st.find(nums[i]) == st.end()){
                v.push_back(nums[i]) ; 
                st.insert(nums[i]) ; 
                solve(nums , v,  st) ;
                v.pop_back() ; 
                st.erase(nums[i]) ; 
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set <int> st ; 
        vector <int> v ;
        solve(nums , v , st) ;
        return ans ; 
        
    }
};