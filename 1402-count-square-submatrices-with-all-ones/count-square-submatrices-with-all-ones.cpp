class Solution {
public:
    vector <vector<int>> dp ;
    int solve(int i , int j ,vector<vector<int>>& v){
        int n = v.size() , m = v[0].size() ;
        if(i >= n || j >= m ) return  0 ;
        if(v[i][j] == 0) return dp[i][j] = 0 ;
        if(dp[i][j] != -1 ) return dp[i][j]  ; 

        int left = 1 + solve(i,j+1,v) ; 
        int down = 1 + solve(i+1,j,v) ; 
        int dia = 1 + solve(i+1,j+1,v) ; 
        int ans = min(left , down ) ; 
        ans = min(ans ,dia) ;
        return dp[i][j] = ans; 
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ; 
        dp.resize(n+5,vector <int> (m+5,-1)) ; 
        int ans =0 ;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m;j++){
                
                ans += solve(i,j,matrix) ; 
            }
        }
        return ans ;
    }
};