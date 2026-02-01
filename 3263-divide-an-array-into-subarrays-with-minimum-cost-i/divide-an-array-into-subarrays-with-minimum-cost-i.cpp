class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0] ;
        int f = INT_MAX ;
        int s= INT_MAX ;
        for(int i = 1 ;i<nums.size() ; i++){
            if(nums[i] < f){
                swap(f,s) ; 
                f = nums[i] ; 
            }
            else if(nums[i] <= s){
                s = nums[i] ; 
            }
        }
        ans += f + s ;
        return ans ;
    }
};