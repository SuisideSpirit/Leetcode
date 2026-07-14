class Solution {
public:
    int MOD = 1e9 + 7 ;
    vector <vector<vector<long long>>> dp ;
    long long solve(int idx ,int gcd1 , int gcd2, vector <int> &nums){
        int n = nums.size() ; 
        if(idx ==n && gcd1 == gcd2 && gcd1 != 0) return 1 ;
        if(idx ==n && gcd1 != gcd2 ) return 0 ;
        if(idx ==n && gcd1 == gcd2 && gcd1 == 0 ) return 0 ;
        if(dp[idx][gcd1][gcd2] != -1) return dp[idx][gcd1][gcd2] ; 

        long long skip = solve(idx + 1 , gcd1 , gcd2 , nums) ; 
        long long take1 = 0 ,take2 = 0 ;
        if(gcd1 == 0)  take1 = solve(idx +1 , nums[idx] , gcd2 , nums) ; 
        else take1 = solve(idx +1 , __gcd(gcd1 , nums[idx]) , gcd2 , nums) ; 
        if(gcd2 == 0) take2 = solve(idx +1 , gcd1, nums[idx], nums) ; 
        else take2 = solve(idx +1 ,gcd1 , __gcd(gcd2 , nums[idx]), nums) ; 

        return dp[idx][gcd1][gcd2] = (skip%MOD + take1%MOD + take2%MOD)%MOD ; 
    }
    int subsequencePairCount(vector<int>& nums) {
        dp.resize(nums.size(),vector <vector<long long>> (205 ,vector <long long> (205,-1))) ; 
        return solve(0,0,0,nums) ; 
    }
};