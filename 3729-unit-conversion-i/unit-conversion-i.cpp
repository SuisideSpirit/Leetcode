class Solution {
public:
    typedef long long ll ;
    int MOD = 1e9 + 7 ; 
    unordered_map <int,vector<pair<int,int>>> mp;
    void Traversal(ll curr ,ll factor , vector <int> &ans ,  vector <int>& visited){
        if(visited[curr]) return ; 
        ans[curr] = factor ; 
        visited[curr] = 1 ;
        for(auto ele : mp[curr]){
            ll next = ele.first , mult = ele.second ; 
            if(visited[next] == 0){
                Traversal(next ,(factor * mult)%MOD ,ans , visited ) ; 
            } 
        }
    }
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1 ;
        vector <int> ans(n) ;  
        for(auto ele : conversions){
            int u = ele[0], v = ele[1], mult = ele[2] ;
            mp[u].push_back({v,mult}) ;  
        }
        vector <int> visited(n,0) ;
        Traversal(0 , 1,  ans,  visited) ; 
        return ans ; 
    }
};