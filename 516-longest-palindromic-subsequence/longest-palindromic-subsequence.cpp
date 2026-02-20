class Solution {
public:
    vector <vector<int>> dp ;
    int solve(int i , int j , string &s){
        if(i > j) return 0 ; 
        if(dp[i][j] != -1) return dp[i][j] ; 
        int both = 0 ;
        if (s[i] == s[j])
            return dp[i][j] = (i == j ? 1 : 2) + solve(i+1, j-1, s);
        int left = solve(i+1, j ,s) ;
        int right = solve(i, j-1 ,s) ;

        return dp[i][j] = max(left , right) ; 
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length() ; 
        dp.resize(n+2,vector<int> (n+2,-1)) ;

        return solve(0,n-1,s) ; 
    }
};