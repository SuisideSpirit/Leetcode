class Solution {
public:
    int smallestNumber(int n) {
        int curr = 1 ; 
        int ans = 0 ;
        while(n>0){
            ans += curr ;
            n -= curr ; 
            curr *= 2 ; 
        }
        return ans ;
    }
};