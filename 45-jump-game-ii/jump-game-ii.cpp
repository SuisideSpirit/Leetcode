class Solution {
public:
    vector <int> dp;  
    int solve(int idx , vector <int> &nums){
        int n = nums.size() ;
        if(idx == n - 1 ) return 0 ; 
        if(dp[idx] != -1) return dp[idx] ;
        int ans = 1e5 ; 
        for(int i = idx +1 ; i <= idx + nums[idx] && i < n ; i++){
            ans = min(ans , 1 + solve(i , nums)) ;
        }
        return dp[idx] = ans ; 
    }
    int jump(vector<int>& nums) {
        int n = nums.size() ; 
        dp.resize(n + 5 , -1) ; 
        return solve(0,nums) ; 
        
    }
};