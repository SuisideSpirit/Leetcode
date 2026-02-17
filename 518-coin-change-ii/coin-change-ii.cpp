class Solution {
public:
    vector <vector<int>> dp ; 
    int solve(int idx , int amount, vector <int>& c){
        if(amount < 0) return 0 ; 
        if(amount == 0 ) return 1 ;
        if(idx >= c.size()) return 0 ;
        if(dp[idx][amount] != -1) return dp[idx][amount] ;
        int ways = 0 ;
        int count = 0 ;
        
        while(amount - count*c[idx] >= 0){
            ways += solve(idx+1,amount - count*c[idx] ,c) ;
            count++;
        }

        return dp[idx][amount] = ways ; 

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size()  ;
        dp.resize(n+5,vector <int> (amount+10 , -1) ) ;
        return solve(0,amount,coins) ;
    }
};