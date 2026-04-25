class Solution {
public:
    bool validDigit(int n, int x) {
        bool flag = false ; 
        while( n >= 10 ){
            int rem = n%10 ; 
            if(rem == x) flag = true ;
            n = n/10 ;
        }
        if(n == x) return false;
        return flag ; 
    }
};