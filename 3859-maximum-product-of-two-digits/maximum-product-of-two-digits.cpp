class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0 ;
        int smax = 0 ; 
        while(n > 0){
            int rem = n%10 ; 
            n /= 10 ; 
            if(rem > maxi){
                smax = maxi ;
                maxi = rem ; 
            }
            else if(rem > smax) smax = rem ; 
        }
        return maxi * smax ; 
        
    }
};