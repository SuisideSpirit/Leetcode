class Solution {
public:
    vector <int> dp ;
    int solve(int idx ,vector<int>& nums){
        int n = nums.size() ;
        if(idx >= n) return 0 ;
        if(dp[idx] != -1) return dp[idx] ; 

        int pick = nums[idx] + solve(idx+2 ,nums ) ;
        int notPick = solve(idx+1,nums) ; 

        return dp[idx] = max(pick , notPick) ;
    }
    int memo(int idx ,vector<int>& nums){
        int n = nums.size() ;
        if(idx < 0) return 0 ;
        if(dp[idx] != -1) return dp[idx] ; 

        int pick = nums[idx] + memo(idx-2 ,nums ) ;
        int notPick = memo(idx-1,nums) ; 

        return dp[idx] = max(pick , notPick) ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ; 
        dp.resize(n+5 , -1)  ;
        return memo(n-1,nums) ;   
    }
};