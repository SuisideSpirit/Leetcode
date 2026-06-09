class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = INT_MIN ,mini = INT_MAX ; 
        for(int i =0 ; i < nums.size() ; i++){
            maxi = max(nums[i] , maxi) ; 
            mini = min(nums[i] , mini) ;
        }

        long long ans = (long long)k * (long long)(maxi - mini ) ;
        return ans ;
        
    }
}; 