class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = 0 ; 
        int n = nums.size() ; 

        for(int i =0 ; i <n ; i++){
            sum += nums[i] ; 
        }
        int curr = 0 ; 
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0 && (curr == sum)){
                ans += 2;
            }
            if(nums[i] == 0 && (curr + 1 == sum || curr == sum + 1)) ans += 1;
            sum -= nums[i] ;
            curr += nums[i] ;
        }
        return ans ;
    }
};