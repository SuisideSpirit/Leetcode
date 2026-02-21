class Solution {
public:
    int bits(int n){
        int c = 0 ;
        while(n > 0 ){
            if(n%2 != 0) c++;
            n = n/2 ;
        }
        return c;
    }
    int is_prime(int n){
        if(n == 1) return 0 ;
        for(int i = 2 ; i<n ;i++){
            if(n%i == 0 ) return 0;
        }
        return 1 ;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0 ;
        vector <int> prime(32,-1) ; 
        for(int i = left ; i<= right ; i++){
            int b = bits(i) ;
            if(prime[b] == -1) prime[b] = is_prime(b) ;
            if(prime[b] == 1) ans++ ;
        }
        return ans ;
    }
};