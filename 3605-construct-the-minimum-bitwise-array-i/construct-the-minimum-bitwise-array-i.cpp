class Solution {
public:
    int MinAns(int n){
        for(int i= 1 ; i<= n ; i++ ){
            if((i | (i+1)) == n) return i ;
        }
        return -1 ;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size() ; 
        vector <int> ans(n,-1) ; 

        for(int i = 0 ; i<n ; i++){
            ans[i] = MinAns(nums[i]) ;
        }
        return ans ;
    }
};