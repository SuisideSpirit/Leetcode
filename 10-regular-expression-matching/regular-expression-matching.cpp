class Solution {
public:
    vector <vector<int>> dp ;
    bool solve(int i , int j , string s , string p){
        int n = s.size() , m = p.size() ; 
        if(j == m) return i == n;
        if(dp[i][j] != -1) return dp[i][j] ; 
        
        bool move = false , stay = false; 

        if(j != m-1 && p[j+1] == '*' && i < n +1 ){
            if(s[i] == p[j] || p[j] == '.') stay = solve(i +1 ,j, s , p) ; 

            move = solve(i, j +2 , s , p) ; 

        }
        else if(i < n && s[i] == p[j] || p[j] == '.') move = solve(i + 1, j +1, s , p) ; 

        return dp[i][j] = move || stay ; 

    }
    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size() ; 
        dp.resize( n +5 ,vector <int> (m+5 , -1)) ; 
        return solve(0 , 0 , s ,p) ;  
        
    }
};