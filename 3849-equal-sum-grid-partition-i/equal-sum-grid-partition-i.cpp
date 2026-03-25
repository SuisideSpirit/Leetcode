class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll n = grid.size() ;
        ll m = grid[0].size() ; 
        ll sum = 0 ; 
        vector <ll> rows(n,0) ; 
        vector <ll> cols(m,0) ; 
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                rows[i] += grid[i][j] ; 
                cols[j] += grid[i][j] ; 
                sum += grid[i][j] ;
            }
        }
        if(sum%2 != 0) return false;
        ll check = sum/2; 
        for(int i = 1; i< n; i++){
            ll curr = rows[i-1] ;
            if(curr == check ) return true ;
            rows[i] += rows[i-1];
        }
        for(int i = 1; i< m; i++){
            ll curr = cols[i-1] ;
            if(curr == check ) return true ;
            cols[i] += cols[i-1];
        }
        return false;
        
    }
};