class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd = n*n ;
        int sumeven = n*(n+1) ; 
        return __gcd(sumodd , sumeven) ;
        
    }
};