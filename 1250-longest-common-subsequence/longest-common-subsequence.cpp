class Solution {
public:
    int n , m ; 
    vector <vector<int>> dp ;
    int solve(int idx1 ,int idx2 ,string & s1 ,string & s2){
        if(idx1 >= n || idx2 >= m) return 0 ; 
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2] ; 
        if (s1[idx1] == s2[idx2]) return dp[idx1][idx2] = 1 + solve(idx1 + 1, idx2 + 1, s1, s2);
        int leave1 = solve(idx1 + 1, idx2 , s1 ,s2);
        int leave2 = solve(idx1 , idx2 + 1 , s1 ,s2);

        leave1 = max(leave1 , leave2) ; 

        return dp[idx1][idx2] = leave1 ; 
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size() , m = text2.size()  ;
        dp.resize(n,vector <int> (m,-1)) ; 
        return solve(0,0,text1 ,text2) ; 
    }
};