class Solution {
public:
    vector <vector<int>> dp ; 
    bool solve(int idx ,int open, string& s ){
        int n = s.size() ; 
        if(idx == n && open == 0) return true ;
        else if(idx == n) return false ;
        if(open < 0 ) return false ; 
        if(dp[idx][open] != -1 ) return dp[idx][open] ; 
        bool ans = false; 
        if(s[idx] == '(') ans = solve(idx +1 , open +1 , s) ; 
        else if(s[idx] == ')') ans = solve(idx +1 , open -1 , s) ; 
        else{
            ans = solve(idx +1 , open + 1 ,s) || solve(idx +1 , open , s) || solve(idx + 1 , open - 1 ,s) ;  
        }
        return dp[idx][open] = ans ; 
    }
    bool checkValidString(string s) {
        int n = s.size() ; 
        dp.resize(n , vector <int> (n , -1)) ;
        return solve(0 , 0 , s) ;  
    }
}; 