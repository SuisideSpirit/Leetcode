class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length() ; 
        int ans = 0 ;
        int prev = 0 ;
        for(int i = 0 ; i <n ; i++){
            int len = 0 ;
            char curr = s[i] ; 
            while(i < n && s[i] == curr ){
                len++;
                i++;
            }
            ans += min(prev , len) ; 
            prev = len ; 
            i--;
        }
        return ans;
        
    }
};