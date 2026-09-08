class Solution {
public:
    int countCommas(int n) {
        int ans = n - 1000 ;
        if(ans < 0 ) return 0 ; 
        return ans +1 ;  

        
    }
};