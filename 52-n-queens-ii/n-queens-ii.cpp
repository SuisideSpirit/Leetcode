class Solution {
public:
    int ans = 0 ;
    void solve(int idx ,int n ,unordered_set <int> &ver ,
    unordered_set <int> &dia,unordered_set <int> &rdia){
        if(idx == n){
            ans += 1 ;
            return ; 
        }
        for(int i = 0 ; i < n ; i++){
            if(ver.find(i) !=  ver.end()) continue ; 
            if(dia.find(i + idx) != dia.end()) continue ;
            if(rdia.find(i - idx) != rdia.end()) continue ;
            
            ver.insert(i) ; 
            dia.insert(i + idx) ; 
            rdia.insert(i - idx) ; 
            solve(idx +1 , n , ver ,dia , rdia) ; 
            ver.erase(i) ; 
            dia.erase(i + idx) ; 
            rdia.erase(i - idx) ;
        }
    }
    int totalNQueens(int n) {
        unordered_set <int> ver , dia , rdia ; 
        solve(0 , n , ver , dia ,rdia) ; 
        return ans ; 
        
    }
};