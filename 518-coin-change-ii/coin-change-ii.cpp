class Solution {
public:
    vector <vector<int>> dp ; 
    int solve(int idx , int amount, vector <int>& c){
        if(amount < 0) return 0 ; 
        if(amount == 0 ) return 1 ;
        if(idx >= c.size()) return 0 ;
        if(dp[idx][amount] != -1) return dp[idx][amount] ;
        int count = 0 ;
        
        int take = 0 ;
        if(amount >= c[idx]) take = solve(idx, amount - c[idx] ,c) ;
        int leave = solve(idx+1,amount,c) ;

        return dp[idx][amount] = take + leave ; 

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size()  ;
        dp.resize(n+5,vector <int> (amount+10 , -1) ) ;
        return solve(0,amount,coins) ;
    }
};