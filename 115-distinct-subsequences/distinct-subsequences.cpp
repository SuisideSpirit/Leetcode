class Solution {
public:
    vector <vector<int>> dp;
    int solve(int i ,int j ,string &s, string &t){
        int n = s.length() ; 
        int m = t.length() ;
        if(j>=m) return 1 ;
        if(i >= n ) return 0 ; 
        if(dp[i][j] != -1) return dp[i][j] ; 

        int take = 0 ;
        if(s[i] == t[j]) take = solve(i+1,j+1,s,t) ;
        int leave = solve(i+1,j,s,t) ; 

        dp[i][j] = leave + take ;
        return dp[i][j] ;
    }
    int numDistinct(string s, string t) {
        int n =s.length() , m = t.length() ;
        dp.resize(n+5,vector<int>(m+5,-1)) ;

        return solve(0,0,s,t) ; 
    }
};