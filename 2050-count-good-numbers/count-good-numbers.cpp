class Solution {
public:
    // int binPow(int x , int n){
    //     long long mod = 1000000007 ;
    //     int ans = 1 ;
    //     long long mult = 1 ;
    //     long long m = 1 ;
    //     for(int i =0 ;i<32 ; i++){
    //         if((n & mult) != 0){
    //             ans = (ans%mod * m)%mod ; 
    //         }
    //         m = (m*x)%mod ;
    //         mult *=2 ;
    //     }
    //     return ans;
    // }
    long long binPow(long long x, long long n) {
        long long result = 1;
        long long mod = 1e9 + 7;
        x %= mod;
        while (n > 0) {
            if (n & 1) {
                result = (result * x) % mod;
            }
            x = (x * x) % mod;
            n >>= 1;  
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        int ans ;
        long long mod = 1000000007 ;
        long long m1 ,m2 ;
        if(n%2 != 0){
            m1 = binPow(5,n/2+1) ;
        }
        else m1 = binPow(5,n/2) ;
        m2 = binPow(4,n/2) ;
        cout<<m1<<" "<<m2;
        ans = ((m1%mod)*(m2%mod))%mod ;
        return ans ;
    }
};