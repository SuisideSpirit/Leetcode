class Solution {
public:
    vector<vector<string>> ans ;
    void solve(int idx ,int n ,vector <string>& temp , unordered_set <int> &ver ,
    unordered_set <int> &dia,unordered_set <int> &rdia){
        if(idx == n){
            ans.push_back(temp) ;
            return ; 
        }
        for(int i = 0 ; i < n ; i++){
            if(ver.find(i) !=  ver.end()) continue ; 
            if(dia.find(i + idx) != dia.end()) continue ;
            if(rdia.find(i - idx) != rdia.end()) continue ;
            
            ver.insert(i) ; 
            dia.insert(i + idx) ; 
            rdia.insert(i - idx) ; 
            temp[idx][i] = 'Q' ; 
            solve(idx +1 , n ,temp , ver ,dia , rdia) ; 
            ver.erase(i) ; 
            dia.erase(i + idx) ; 
            rdia.erase(i - idx) ;
            temp[idx][i] = '.' ;  
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        unordered_set <int> ver , dia , rdia ; 
        vector <string> temp ; 
        string s = "" ; 
        for(int i = 0 ; i < n ; i++) s = s + "." ; 
        for(int i = 0 ; i < n ; i++) temp.push_back(s) ;
        solve(0 , n , temp , ver , dia ,rdia) ; 
        return ans ; 
        
    }
};