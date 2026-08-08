class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> ans ; 
        int n = nums.size() ;
        set <vector<int>> st ;  
        sort(nums.begin() , nums.end()) ; 
        for(int i = 0 ; i < n ;i++){
            int req = -nums[i] ; 
            int low = i +1  , high = n-1 ; 
            while(low < high){
                int curr = nums[low] + nums[high] ; 
                if(curr > req){
                    high-- ;
                }
                else if(curr < req) low++ ; 
                else{
                    st.insert({nums[i] , nums[low] , nums[high]}) ;
                    low++ ;
                }
            }
        }
        for(auto ele : st) ans.push_back(ele) ; 
        return ans ; 
        
    }
};