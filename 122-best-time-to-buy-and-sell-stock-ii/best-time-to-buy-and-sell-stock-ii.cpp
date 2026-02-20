class Solution {
public:
    vector <vector<int>> dp ;
    int solve(int i, int hold , vector<int>& prices){
        int n = prices.size() ; 
        if(i >= n ) return 0 ; 
        if(dp[i][hold] != -1) return dp[i][hold]  ;
        int take = 0 , leave = 0 ;
        leave = solve(i+1,hold,prices) ;
        if(hold == 1) take = prices[i] + solve(i,0,prices) ; 
        else take = solve(i+1,1,prices) - prices[i] ; 

        return dp[i][hold] = max(take,leave) ; 
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        dp.resize(n+5,vector<int> (3,-1)) ; 
        return solve(0,0,prices) ; 
    }
};