class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int maxi = nums[0] , mini= nums[n-1] ; 
        vector <int> prefix(n)  ,suffix(n) ; 
        for(int i = 0 ; i < n ; i++){
            maxi = max(nums[i] , maxi) ;
            prefix[i]  = maxi ; 
        } 
        for(int i = n-1; i >= 0 ; i--){
            mini = min(nums[i] , mini) ;
            suffix[i]  = mini ; 
        } 
        for(int i = 0 ; i < n ; i++){
            if(prefix[i] - suffix[i] <= k) return i ;
        }
        return -1 ; 
        
    }
}; 