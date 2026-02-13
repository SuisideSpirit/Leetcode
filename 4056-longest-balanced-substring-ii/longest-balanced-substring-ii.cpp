class Solution {
public:
    int helper(string&s , char ch1 , char ch2){
        int n = s.length() ;
        int c1 = 0, c2 = 0 ;
        int ans = 0 ; 
        unordered_map <int,int> mp ;
        mp[0] = -1 ;
        for(int i = 0 ; i <n ;i++){
            if(s[i] == ch1 ) c1++;
            else if(s[i] == ch2 ) c2++;
            else {
                c1 = 0 ; 
                c2 = 0 ;
                mp.clear() ; 
                continue ;
            }
            if(c2 == c1){
                ans = max(ans,c1 + c2) ;
            }
            int diff = c1 - c2 ; 
            if(mp.count(diff)){
                ans = max(ans, i - mp[diff]) ; 
            }
            else mp[diff] = i ;
        }
        return ans ;
    }
    int longestBalanced(string s) {
        int n = s.length() ; 
        int maxL = 1 , count = 1; 
        for(int i = 1 ; i < n ;i++){
            if(s[i] == s[i-1] ) count++;
            else count = 1; 
            maxL = max(count , maxL) ;
        }
        maxL = max(maxL,helper(s, 'a' ,'b')) ;
        maxL = max(maxL,helper(s, 'a' ,'c')) ;
        maxL = max(maxL,helper(s, 'c' ,'b')) ;
        
        int counta = 0 , countb = 0 , countc = 0 ;

        unordered_map <string, int> mp ;
        for(int i = 0 ; i <n ; i++){
            if(s[i] == 'a') counta++;
            else if(s[i] == 'b') countb++; 
            else countc++;
            if(counta == countb && countb == countc){
                maxL = max(maxL , counta + countb + countc) ; 
            }
            int diffAB = counta - countb ;
            int diffAC = counta - countc ; 
            string key = to_string(diffAB) + "-" + to_string(diffAC) ;
            if(mp.count(key)){
                maxL = max(maxL ,i -  mp[key]) ;
            }
            else mp[key] = i ;
        } 
        return maxL ;
        
    }
}; 