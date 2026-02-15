class Solution {
public:
    vector <vector <int>> dp ;
    int solve(int i , int j , int m , int n){
        if(i >= m || j >= n) return 0 ;
        if(i == m-1 && j == n-1) return 1 ;
        if(dp[i][j] != -1 ) return dp[i][j] ; 
        int left = solve(i,j+1,m,n) ;
        int down = solve(i+1,j,m,n) ;
        return dp[i][j] = left + down; 
    }
    int uniquePaths(int m, int n) {
        dp.resize(m+1, vector <int> (n+5,-1)) ; 
        return solve(0,0,m,n) ; 
    }
};