class Solution {
public:
    int change(vector<int>& nums){
        int n = nums.size()  ;
        int idx = -1 ;
        int minSum = INT_MAX ; 
        for(int i= 0; i<n-1 ;i++){
            if(minSum > nums[i] + nums[i+1] ){
                minSum = nums[i] + nums[i+1] ; 
                idx = i ;
            }
        }
        return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 ;
        while(!is_sorted(nums.begin() , nums.end())){
            int idx = change(nums) ; 

            nums[idx] += nums[idx+1] ; 

            nums.erase(begin(nums) + idx +1) ;
            ans += 1; 
        }
        return ans ;
    }
};