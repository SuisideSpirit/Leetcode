class Solution {
public:
    vector <int> dp; 
    bool solve(int idx , vector <int> &nums){
        int n = nums.size() ; 
        if(idx >= n  ) return false ; 
        if(idx != n-1 && nums[idx] == 0 ) return false ;
        if(dp[idx] != -1) return dp[idx] ; 
        if(idx == n-1 )return true ; 

        bool ans = false ;
        for(int i = 1 ; i <= nums[idx]; i++){
            if(idx + i < n && dp[idx+ i] != 0)
            ans = ans | solve(idx + i , nums) ; 
            if(ans) return ans ;
        }
        return dp[idx] = ans ; 
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size() ; 
        dp.resize(n+ 5 ,-1) ; 
        return solve(0 , nums) ; 
        
    }
};