class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size() ; 
        bool ans = true ;
        sort(nums.begin() , nums.end()) ; 
        bool Odd = false , Even= false ;
        for(int i =0 ; i < n ; i++){
            if(nums[i]%2 !=0 ){
                ans = false ;
                break ;
            }
        }
        if(ans) return ans ;
        ans = true ;
        //check for odd
        for(int i = 0 ; i < n ; i++){
            if(nums[i]%2 == 0 && Odd == false ){
                ans = false; 
                break ; 
            }
            else Odd = true ; 
        }
        return ans  ; 
    }
};