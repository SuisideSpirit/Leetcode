class Solution {
public:
    bool isPalindrome(string &s , int l , int r){
        while(l <= r){
            if(s[l] != s[r]) return false; 
            l++;
            r-- ;
        }
        return true ;
    }
    vector <int> dp ;
    int solve(int idx ,string &s){
        int n = s.size() ; 
        if(idx == n ) return 0 ; 
        
        if(dp[idx] != -1) return dp[idx] ; 

        int ans = n ; 
        for(int i = idx; i < n ; i++){
            if(isPalindrome(s,idx,i)){
                ans = min(ans ,1+ solve(i + 1 , s)) ; 
            }
        }

        return dp[idx] = ans ;
    }
    int minCut(string s) { 
        int n= s.size();
        dp.resize(n + 5 , -1) ; 
        return solve(0,s) -1; 
    }
};