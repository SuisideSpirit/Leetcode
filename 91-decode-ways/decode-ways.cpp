class Solution {
public:
    vector <int> dp ;
    int solve(int idx , string& s){
        int n = s.size() ;
        if(idx == s.size()) return 1 ;
        if(idx >= s.size() || s[idx] == '0') return 0 ; 
        if(dp[idx] != -1) return dp[idx] ; 

        int ans = 0 ;
        if(s[idx] == '1'  && idx != n-1) ans += solve(idx +2 , s) ; 
        else if(s[idx] == '2' && idx != n-1 && s[idx +1] < '7') ans +=  solve(idx +2 , s) ;

        ans += solve(idx+ 1 , s) ; 

        return dp[idx] = ans ;
    }
    int numDecodings(string s) {
        int n = s.size() ; 
        //if(s[0] == '0') return 0 ; 
        dp.resize( n + 5 , -1) ; 
        return solve(0 , s) ; 
    }
};