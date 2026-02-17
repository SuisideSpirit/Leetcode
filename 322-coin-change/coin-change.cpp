class Solution {
public:
    vector <vector<int>> dp ; 
    int solve(int i , int amount ,vector<int>& c){
        if(amount == 0 ) return 0 ; 
        if(amount < 0 || i < 0) return 100000;
        if(i == 0 && amount%c[i] == 0) return amount/c[i] ;
        if(dp[i][amount] != -1) return dp[i][amount] ; 
        int count = 0 ; 
        int ans = 100000 ; 
        while(amount - count*c[i] >= 0){
            ans = min(ans,count + solve(i-1, amount - count*c[i] , c)) ;
            count++;
        }
        return dp[i][amount] = ans ;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ; 
        dp.resize(n+5 , vector <int> (amount+10 , -1)) ; 
        int ans = solve(n-1,amount,coins) ;
        if(ans > 10000) return -1 ;
        else return ans ;
    }
};