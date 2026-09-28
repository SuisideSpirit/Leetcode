class Solution {
public:
    int maxDepth(string s) {
        int start = 0 ; 
        int ans =0 ; 
        for(int i = 0 ; i < s.size() ;i++){
            if(s[i] == '(') start++;
            if(s[i] == ')') start-- ; 
            ans = max(ans , start) ; 
        }
        return ans ;
        
    }
};