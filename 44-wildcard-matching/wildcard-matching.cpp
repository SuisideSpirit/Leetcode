class Solution {
public:
    vector <vector<int>> dp;
    bool solve(int i , int j ,string &s, string &p){
        int n = s.size() ; 
        int m = p.size() ; 
        if(dp[i][j] != -1) return dp[i][j] ;
        if(i == n && j == m ) return dp[i][j] = true ;
        if(i >= n+1 || j >= m ) return dp[i][j] = false ;

        if(p[j] == '?') return dp[i][j] = solve(i+1,j+1,s,p) ;
        if(p[j] != '*' && s[i] != p[j]) return dp[i][j] = false;
        if(p[j] != '*' && s[i] == p[j]) return dp[i][j] = solve(i+1,j+1,s,p);
        
        bool take = solve(i+1,j,s,p) ;
        bool leave = solve(i,j+1,s,p) ;
        bool end = solve(i+1,j+1,s,p) ;

        return dp[i][j] = take || leave || end;
    }
    bool isMatch(string s, string p) {
        int n = s.size() ; 
        int m = p.size() ; 
        dp.resize(n+5,vector<int> (m+5,-1)) ;
        return solve(0,0,s,p) ;
    }
};