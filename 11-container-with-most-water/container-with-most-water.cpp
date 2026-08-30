class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size() ; 
        int low = 0 , high = n -1 ;
        int ans = 0 ;
        while(low <= high){
            int width = (high - low) ;
            ans = max(ans , width * min(nums[high] , nums[low])) ; 
            if(nums[low] < nums[high]) low++ ;
            else high-- ;
        }
        return ans ; 
        
    }
};