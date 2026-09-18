class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size() ; 
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 1){
                int st = i ; 
                while(i < n && nums[i] == 1){
                    i++;
                }
                ans = max(ans , i - st) ; 
            }
        }
        return ans ;
        
    }
};