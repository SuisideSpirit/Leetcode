class Solution {
public:
    int MULT = 1 ;
    int binary(int n){
        int MOD = 1000000007 ;
        int ans = 0 ;
        while(n > 0){
            if(n%2 == 1){
                ans = (ans%MOD + MULT%MOD)%MOD;
            }
            MULT = (MULT*2)%MOD;
            n/=2 ; 
        }
        return ans ;
    }
    int concatenatedBinary(int n) {
        string s = "" ;
        string temp = "0" ;
        int MOD = 1000000007 ;
        int ans = 0 ;
        for(int i = n ; i>=0 ; i--){
            ans = (ans%MOD + binary(i)%MOD)%MOD ;
        } 
        return ans;

        
    }
};