class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size() ;
        int open = 0 ; 
        string ans = "" ;  
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') open++; 
            if(open != 1 ) ans = ans + s[i] ; 
            if(s[i] == ')') open--; 
        }
        return ans ; 
        
    }
};