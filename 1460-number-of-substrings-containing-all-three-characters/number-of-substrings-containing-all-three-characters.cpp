class Solution {
public:
    int solve(int idx , vector <int> &v1 , vector <int>&v2){
        int n = v1.size() ; 
        if(v1[idx] == -1 || v2[idx] == -1) return 0 ; 

        int i = max(v1[idx] , v2[idx]) ; 
        return n - i ; 
    }

    int numberOfSubstrings(string s) {
        int n = s.size() ; 
        vector <int> nextA(n,-1) , nextB(n,-1) , nextC(n,-1) ; 
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == 'a'){
                nextA[i] = i ; 
                if(i!=n-1){
                    nextB[i] = nextB[i+1] ; 
                    nextC[i] = nextC[i+1] ;
                }
            }
            else if(s[i] == 'b'){
                nextB[i] = i ; 
                if(i != n-1){
                   nextA[i] = nextA[i+1] ; 
                    nextC[i] = nextC[i+1] ; 
                }
            }
            else{
                nextC[i] = i ;
                if(i!=n-1){
                    nextB[i] = nextB[i+1] ; 
                    nextA[i] = nextA[i+1] ;
                } 
            }
        }
        int ans = 0 ; 
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a') ans += solve(i ,nextB , nextC) ; 
            else if(s[i] == 'b') ans += solve(i ,nextA , nextC) ;
            else ans += solve(i,nextA , nextB) ;

        }
        return ans; 
    }
};