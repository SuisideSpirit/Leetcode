class Solution {
public:
    vector <vector<int>> dp;
    int solve(int i1 , int i2 ,string &word1, string &word2){
        if(i1 >= word1.size() && i2 >= word2.size()) return 0 ; 
        if(dp[i1][i2] != -1) return dp[i1][i2] ;
        int del1 = INT_MAX , del2 = INT_MAX , leave = INT_MAX;
        if(i1 < word1.size()) del1 = 1 + solve(i1+1,i2, word1 ,word2) ;
        if(i2 < word2.size()) del2 = 1 + solve(i1,i2+1, word1 ,word2) ;
        if(word1[i1] == word2[i2]) leave = solve(i1+1,i2 +1 , word1 ,word2) ;

        int ans = min(del1,del2) ; 
        ans= min(ans,leave) ;
        return dp[i1][i2] = ans ;
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size() , n2 = word2.size() ;
        dp.resize(n1+5, vector<int> (n2+5,-1)) ;
        return solve(0,0,word1,word2) ; 
    }
};