class Solution {
public:
    vector <vector<vector<int>>> dp ;
    int solve(int idx, int k ,int hold, vector <int> &nums){
        int n = nums.size() ;
        if(idx >= n) return 0 ;
        if(idx == n-1){
            if(hold == 1) return nums[idx] ;
            else return 0 ; 
        }
        if(dp[idx][k][hold] != -1) return dp[idx][k][hold] ; 
        int leave = solve(idx +1 , k , hold , nums) ; 
        int take = 0 ; 
        if(hold == 1 ){
            take = nums[idx] +  solve(idx +1 , k , 0 , nums) ; 
        }
        if(hold == 0 && k > 0 ){
            take = solve(idx+ 1 , k-1 , 1, nums) - nums[idx] ; 
        }
        return dp[idx][k][hold] = max(take , leave) ; 
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        dp.resize(n + 5 , vector <vector<int>> (k + 2 , vector <int> (3,-1))) ; 
        return solve(0 , k , 0 , prices)  ;
    }
};