class Solution {
public:
    int binary_search(int st , int t , vector <int> &nums){
        int high = nums.size() -1 , low = st ; 
        int ans = nums.size() -1  ; 
        while(low <= high){
            int mid = (low + high)/2 ; 
            if(nums[mid] >= t){
                ans = mid ; 
                high = mid - 1 ; 
            }
            else low = mid + 1 ; 
        }
        return ans ; 
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size() ; 
        if(n == 3) return nums[0] + nums[1] +  nums[2] ; 
        sort(nums.begin() , nums.end()) ;
        int ans = -1 , diff = INT_MAX ;
        for(int i = 0 ; i < n-2 ; i++){
            for(int j = i + 1 ; j < n-1 ; j++){
                int t = target - (nums[i]  + nums[j]) ;
                int idx = binary_search(j + 1 , t , nums) ;
                int temp = nums[i] + nums[j] + nums[idx] ; 
                if(abs(temp - target) < diff){
                    diff = abs(temp - target) ;
                    ans = temp ; 
                }
                if(idx != j +1 ){
                    temp = nums[i] + nums[j] + nums[idx -1] ; 
                    if(abs(temp - target) < diff){
                        diff = abs(temp - target) ;
                        ans = temp ; 
                    }
                } 

            }
        }
        return ans ; 
        
    }
};