class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& idx) {
        int n = nums.size() ; 
        unordered_map <int,int> mp ;
        for(int i =0 ; i <n+1;i++){
            mp[i] = -1 ;
        }
        for(int i =0 ; i <n ;i++){
            if(mp[idx[i]] == -1){
                mp[idx[i]] = i ;
            }
            else{
                int store = mp[idx[i]] ;
                mp[idx[i]] = i ; 
                int j = idx[i]+1 ; 
                while(mp[j] != -1){
                    int temp = store ;
                    store = mp[j] ;
                    mp[j] = temp ;
                    j++;
                }
                mp[j] = store ;
            }
        }
        vector <int> ans(n,0) ; 
        for(int i = 0 ;i < n ; i++){
            ans[i] = nums[mp[i]] ;
        }
        return ans;
    }
};