class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size() ;
        vector <int> prefix(n) ;
        int mx = 0 ; 
        for(int i = 0 ; i < n ; i++){
            mx=  max(mx , nums[i]) ; 
            prefix[i] = __gcd(mx, nums[i]) ; 
        }
        sort(prefix.begin() , prefix.end()) ; 
        long long ans = 0 ; 
        for(int i =0 ; i < n/2 ; i++){
            ans += __gcd(prefix[i] , prefix[n-1-i]) ; 
        }
        return ans ;
        
    }
};