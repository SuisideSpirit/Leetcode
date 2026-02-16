class Solution {
public:
    typedef long long ll ;
    int reverseBits(int n) {
        vector <int> v(32,0) ; 
        for(int i = 0 ; i < 32 ; i++){
            v[i] = n%2 ;
            n /= 2 ;
        }
        ll temp = 1 ;
        ll ans = 0 ;
        for(int i = 31 ; i>= 0 ; i--){
            if(v[i] == 1) ans += temp ;
            temp *= 2 ;
        }
        return ans ;
        
    }
};