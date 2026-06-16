class Solution {
public:
    vector <int> dp ;
    int solve(int idx,vector<int>& nums){
        int n = nums.size() ; 
        if(idx == n-1 ) return dp[n-1] = 1; 
        if(idx >= n ) return 0;
        if(dp[idx] != -1) return dp[idx] ;
        int len = 0 ;  
        cout<<idx<<endl;
        for(int i = 1 ; i + idx < n ; i++){
            if(nums[idx + i] > nums[idx] ) len = max(len, solve(idx + i,nums)) ; 
        }
        return dp[idx] = len +1 ;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ; 
        dp.resize(n+5,-1) ;
        int ans =1 ;  
        for(int i = 0 ; i < n ; i++){
            ans = max(ans,solve(i,nums)) ; 
        }
        for(int i = 0 ; i < n ; i++) cout<<dp[i]<<" ";
        return ans ;
    }
}; 