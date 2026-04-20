class Solution {
public:
    typedef long long ll ; 
    vector <int> v  ;
    ll solve(int idx ,vector<int>& arr, int k){
        int n = arr.size() ; 
        if(idx >= n) return 0 ; 
        if(v[idx] != -1) return v[idx] ;

        int maxi = arr[idx] ; 
        ll ans = 0 ; 
        for(int i = 0 ; i < k && i + idx < n ; i++){
            maxi = max(maxi,arr[idx + i]) ; 
            ans = max(ans,maxi*(i+1) + solve(idx+ i+ 1,arr,k)) ;
        }
        return v[idx] = ans ; 
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size() ;
        v.resize(n+5,-1) ;
        return solve(0,arr,k) ; 
    }
}; 