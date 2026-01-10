class Solution {
public:
    vector <vector<long long>> dp ;
    long long solve(int i , int j , string &s1, string &s2){
        if(i >=  s1.length() && j >= s2.length()) return 0 ; 
        if(dp[i][j] != -1) return dp[i][j] ; 
        if(i >=  s1.length()){
            return dp[i][j] = (long long)(s2[j]) + solve(i,j+1,s1,s2) ; 
        }
        if(j >=  s2.length()){
            return dp[i][j] = (long long)(s1[i]) + solve(i+1,j,s1,s2) ; 
        }
        long long extra = INT_MAX ; 
        if(s1[i] == s2[j]){
            extra = solve(i+1,j+1,s1,s2) ;
        }
        long long leave1 = (long long)(s1[i]) + solve(i+1,j,s1,s2) ; 
        long long leave2 = (long long)(s2[j]) + solve(i,j+1,s1,s2) ; 

        return dp[i][j] = min(extra , min(leave1,leave2)) ; 
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length() ; 
        int m = s2.length() ; 

        dp.resize(n+5,vector<long long> (m+5,-1)) ;
        return solve(0,0,s1,s2)  ;
    }
};