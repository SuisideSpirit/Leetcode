class Solution {
public:
    int totalMoney(int n) {
        int ans = 0 ;
        int start = 1 ; 
        while(n>0){
            int t ;
            if(n>=7) t=  7 ;
            else t=n;
            int temp = (t*(2*start + (t-1)))/2 ; 
            ans += temp ;
            start++;
            n -= 7 ;
        }
        return ans ;
        
    }
};