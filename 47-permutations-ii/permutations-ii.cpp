class Solution {
public:
    vector <vector<int>> ans ; 
    void solve(int idx ,vector <int>& v , unordered_map <int,int> &mp){
        int n = v.size() ; 
        if(idx == n){
            ans.push_back(v) ; 
        }
        for(auto ele : mp){
            int num = ele.first ; 
            int f = ele.second ;
            if(f == 0 ) continue ; 
            mp[num]-- ; 
            v[idx] = num ; 
            solve(idx +1  ,v ,mp) ; 
            mp[num]++ ;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size()  ;
        unordered_map <int,int> mp ; 
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++; 
        }
        vector <int> v(n) ; 
        solve(0 , v, mp) ;
        return ans ; 

        
    }
};