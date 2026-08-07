class Solution {
public:
    vector <vector<int>> dp ;
    int solve(int amount ,int idx, vector <int>& coins){
        int n = coins.size() ;
        if(idx >= n || amount < 0 ) return 1e5 ; 
        if(amount == 0) return 0 ; 
        if(dp[amount][idx] != -1) return dp[amount][idx] ; 
        
        int take = 1 + solve(amount - coins[idx] , idx , coins) ; 
        int leave = solve(amount , idx +1 , coins) ; 

        return dp[amount][idx] = min(take , leave) ; 
    }
    int coinChange(vector<int>& coins, int amount) {   
        int n= coins.size() ;  
        dp.resize(1e4 + 5 ,vector <int> (n , -1)) ; 

        int ans = solve(amount,0,coins) ; 

        if(ans > 1e4) return -1 ;
        else return ans; 
        
    }
};