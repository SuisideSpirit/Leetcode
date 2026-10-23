class Solution {
public:
    vector <vector<int>> dp ; 
    int solve(int st ,int end , vector <int>&v){
        if(st > end) return 0 ; 
        int ans = INT_MIN ; 
        if(dp[st][end] != -1) return dp[st][end] ; 
        for(int i = st ; i <= end ; i++ ){
            int temp = v[i]*v[st-1]*v[end+1] + solve(st , i-1 , v) + solve(i+1 , end, v) ; 
            ans = max(ans, temp ); 
        }
        return dp[st][end] = ans; 
    }
    int maxCoins(vector<int>& nums) {
        vector <int> v ; 
        v.push_back(1) ; 
        int n = nums.size() ; 
        for(int i = 0 ; i < n ; i++) v.push_back(nums[i]) ; 
        v.push_back(1);
        dp.resize(n+5 , vector <int> (n+5 , -1)) ; 
        return solve(1,v.size()-2,v) ; 
    }
};