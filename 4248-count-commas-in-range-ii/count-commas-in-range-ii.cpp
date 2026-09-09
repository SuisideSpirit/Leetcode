class Solution {
public:
    long long countCommas(long long n) {
        long long ans= 0 ;
        long long  temp =1000 ; 
        while(temp <= n){
            ans += (n - temp) ; 
            temp = temp * 1000 ; 
            ans += 1 ; 
        }
        return ans ;
    }
};