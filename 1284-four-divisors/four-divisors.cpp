class Solution {
public:
    int check4(int n){
        int numDiv = 2 ;
        int div = 0 ;
        for(int i = 2; i<=sqrt(n) ; i++){
            if(i == sqrt(n) && n%i == 0) numDiv +=1 ; 
            else if(n%i == 0 ){
                numDiv += 2 ;
                div = i ;
            }
        }
        if(numDiv == 4){
            return n + 1 + div + n/div ;
        }
        return 0 ;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size() ; 
        int ans = 0 ;
        for(int i= 0 ; i<n ;i++){
            ans += check4(nums[i]) ;
        }
        return ans ;
    }
};