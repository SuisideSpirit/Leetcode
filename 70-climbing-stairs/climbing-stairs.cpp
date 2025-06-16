// class Solution {
// public:
//     int climbStairs(int n) {
        
//     }
// };
class Solution {
public:
    vector <int> dp;
    int solve(int n) {
        if(n == 0) return 1 ; 
        if(n < 0) return 0; 
        if(dp[n] != -1) return dp[n] ;
        
        int s1 = solve(n-1) ;
        int s2 = solve(n-2) ;

        return dp[n] = s1 + s2 ;
    }
    int climbStairs(int n) {
        dp.resize(50,-1) ; 
        return solve(n) ;
    }
};