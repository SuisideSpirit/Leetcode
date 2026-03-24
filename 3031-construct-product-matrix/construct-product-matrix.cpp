class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD = 12345 ;
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        
        vector<vector<int>> prefix(n,vector <int> (m,1)) ; 
        vector<vector<int>> suffix(n,vector <int> (m,1)) ; 
        vector<vector<int>> ans(n,vector <int> (m,1)) ; 

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(i == 0 && j== 0 ) continue ;
                if(j == 0){
                    prefix[i][j] = (prefix[i-1][m-1]%MOD) * (grid[i-1][m-1]%MOD) ; 
                }
                else prefix[i][j] = (grid[i][j-1]%MOD) * (prefix[i][j-1]%MOD) ; 
            }
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                if(i == n-1 && j== m-1 ) continue ;
                if(j == m-1){
                    suffix[i][j] = (suffix[i+1][0]%MOD) * (grid[i+1][0]%MOD) ; 
                }
                else suffix[i][j] = (grid[i][j+1]%MOD) * (suffix[i][j+1]%MOD); 
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< m ; j++){
                ans[i][j] = ((prefix[i][j]%MOD) * (suffix[i][j]%MOD))%MOD ;
            }
        }
        return ans ;
    }
};