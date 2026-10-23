class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() ; 
        int low = 0 , high =n-1 ; 
        int ans = 0 ; 
        while(low <= high){
            int mid = (low + high)/2 ; 
            if(nums[mid] > nums[high] ){
                low = mid + 1 ; 
            }
            else{
                high = mid - 1;
            }
            if( nums[ans] > nums[mid]) ans = mid ; 
        }
        return nums[ans] ; 
        
    }
};