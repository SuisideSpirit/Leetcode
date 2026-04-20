class Solution {
public:
    int check(int part ,vector<int>& v){
        int n = v.size() ; 
        int splits = 0 ;
        int curr = 0 ; 
        for(int i = 0 ; i < n ; i++){
            splits++;
            curr = 0 ;  
            while(i!= n && curr + v[i] <= part){
                curr += v[i] ; 
                i++;
            }
            i-- ; 
        }
        return splits ; 

    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector <int> prev(n,0) ;
        int low = 0 ; 
        int high = 0; 
        for(int i = 0 ; i <n ; i++){
            low = max(nums[i] , low) ;
            high += nums[i] ; 
        }
        int ans = INT_MAX ; 
        while(low <= high){
            int mid = (low + high)/2 ; 
            int splits = check(mid ,nums) ; 
            if(splits <= k){
                high = mid - 1 ;
            }
            else if(splits > k){
                low = mid + 1 ;
            }
        }
        return low; 
    }
};