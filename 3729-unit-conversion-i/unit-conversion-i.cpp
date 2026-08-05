class Solution {
public:
    typedef long long ll ;
    int MOD = 1e9 + 7 ; 
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1 ;
        vector <int> ans(n) ; 
        unordered_map <int,vector<pair<int,int>>> mp; 
        for(auto ele : conversions){
            int u = ele[0], v = ele[1], mult = ele[2] ;
            mp[u].push_back({v,mult}) ;  
        }
        queue <pair<ll,ll>> q ; 
        q.push({0,1}) ; 
        vector <ll> visited(n , 0) ; 
        visited[0] = 1; 
        while(q.size() != 0 ){
            auto ele = q.front() ; 
            q.pop();
            ll curr = ele.first, quan = ele.second ; 
            ans[curr] = quan ;
            for(auto ele : mp[curr]){
                ll next = ele.first , mult = ele.second ; 
                if(visited[next] == 0){
                    q.push({next , (quan* mult)%MOD}) ; 
                    visited[next] = 1 ;
                } 
            }
        }
        return ans ; 
    }
};