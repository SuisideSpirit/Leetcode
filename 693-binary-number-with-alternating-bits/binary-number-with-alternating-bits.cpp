class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr = n%2 ; 
        while(n > 0){
            if(n%2 != curr) return false ;
            curr = 1 - curr ; 
            n /= 2 ;
        }
        return true; 
    }
};