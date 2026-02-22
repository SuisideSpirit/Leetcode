class Solution {
public:
    int binaryGap(int n) {
        int f = -1 , l = -1 ;
        int d = 0 ;
        int ans = 0 ; 
        while(n > 0){
            d++;
            if(n%2 != 0){
                l = d ; 
                if(f!= -1) ans = max(l-f,ans) ;
                f = d ;
            }
            n /= 2 ;
        }
        return ans ;
        
    }
};