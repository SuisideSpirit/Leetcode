class Solution {
public:
    int n ;
    vector <int> dp ;
    int binary_search(int idx, int e , vector <pair<int,pair<int,int>>> &v){
        int low = idx , high = v.size() -1 ; 
        int ans = n ; 
        while(low <= high){
            int mid = (low + high)/2 ; 
            if(v[mid].first >= e){
                ans = mid ; 
                high = mid -1 ; 
            }
            else low = mid + 1;
        }
        return ans ;

    }
    int solve(int idx, vector <pair<int,pair<int,int>>> &v ){
        if(idx >= n) return 0 ; 
        if(dp[idx] != -1) return dp[idx] ; 
        int leave = solve(idx +1 , v)  ;
        int s = v[idx].first ,e= v[idx].second.first, p = v[idx].second.second ;
        
        int index = binary_search(idx +1 , e, v ) ;
        int take = p + solve(index , v) ; 
        return dp[idx]=max(take , leave) ; 
    }
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        n = start.size() ;
        vector <pair<int,pair<int,int>>> v ;
        dp.resize(n+5 ,-1) ; 
        for(int i = 0 ; i < n ; i++){
            v.push_back({start[i] ,{end[i] , profit[i]}}) ; 
        }
        sort(v.begin() , v.end()) ; 
        return solve(0,v) ; 
        
    }
};