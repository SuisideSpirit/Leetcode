class Solution {
public:
    vector <vector<int>> dp;
    int solve(int i , int t ,vector <int>& v){
        if(t == 0) return 1 ;
        if(t < 0) return 0 ; 
        if(i >= v.size()) return 0 ; 
        if(dp[i][t] != -1) return dp[i][t] ;  
        int take = solve(i+1,t-v[i] , v) ;
        int leave = solve(i+1,t,v) ; 

        return dp[i][t] = max(leave,take) ; 
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 ;
        for(int i = 0 ;i<n ; i++){
            sum += nums[i] ; 
        }
        dp.resize(n+2,vector <int> (sum,-1)) ;
        if(sum%2 != 0) return false ;
        else return solve(0,sum/2,nums) ;
    }
};