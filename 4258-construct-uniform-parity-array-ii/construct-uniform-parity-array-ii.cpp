class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size() ; 
        bool ans = true ;
        int mini = INT_MAX ;
        bool Odd = false ;
        for(int i = 0 ; i  <n ; i++){
            mini = min(mini, nums[i]) ;
            if(nums[i] %2 != 0) Odd = true ; 
        }
        if(mini%2 != 0) return true ;
        if(!Odd) return true; 
        return false; 
        // bool Odd = false , Even= false ;
        // for(int i =0 ; i < n ; i++){
        //     if(nums[i]%2 !=0 ){
        //         ans = false ;
        //         break ;
        //     }
        // }
        // if(ans) return ans ;
        // ans = true ;
        // //check for odd
        // for(int i = 0 ; i < n ; i++){
        //     if(nums[i]%2 == 0 && Odd == false ){
        //         ans = false; 
        //         break ; 
        //     }
        //     else Odd = true ; 
        // }
    }
};