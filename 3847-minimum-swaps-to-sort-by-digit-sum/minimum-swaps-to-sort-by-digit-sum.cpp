class Solution {
public:
    int solve(int n){
        int ans = 0 ; 
        while(n > 0){
            ans += n%10 ; 
            n = n/10 ; 
        }
        return ans ;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size() ; 
        vector <pair<int,int>> v; 
        for(int i = 0 ; i < n ; i++){
            int sum = solve(nums[i]) ;
            v.push_back({sum , nums[i]}) ; 
        }
        sort(v.begin() , v.end()) ; 
        unordered_map <int,int> mp ; 
        
        int swaps = 0 ; 
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]] = i ;
        }
        for(int i = 0 ; i< n ; i++){
            int idx = mp[v[i].second] ;
            if(idx == i) continue ;
            int req = nums[i] ;
            swap(nums[i] , nums[idx]) ; 
            mp[nums[i]] = i ; 
            mp[nums[idx]] = idx ;
            swaps++ ;
        }
        return swaps ;

        
    }
};