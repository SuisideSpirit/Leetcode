class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() ; 
        int ans = 0 ;
        for(int i = n-1 ; i>= 0 ; i--){
            if(s[i] == ' ') continue ; 
            while( i >= 0 && s[i] != ' '){
                ans++; 
                i--;
            }
            return ans;  
        }
        return ans ; 
        
    }
};