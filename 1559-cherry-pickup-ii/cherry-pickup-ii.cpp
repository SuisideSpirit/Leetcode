class Solution {
public:
    vector <vector<vector<int>>> dp ;
    int solve(int i ,int j1 ,int j2 , vector<vector<int>>& g){
        int n = g.size () , m = g[0].size() ;
        if(i >= n || i < 0) return 0 ;
        if(j1 >= m || j1 < 0) return 0 ;
        if(j2 >= m || j2 < 0) return 0 ;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2] ; 

        int ans = g[i][j1] + g[i][j2] ;
        if(j1 == j2) ans -= g[i][j1] ; 
        int movements[] = {-1, 1, 0};
        int temp = 0 ; 
        for(int x = 0 ; x < 3 ; x++){
            for(int y = 0 ; y < 3 ;y++){
                temp = max(temp , solve(i+1,j1 + movements[x] , j2 + movements[y],g)) ;
            }
        }

        return dp[i][j1][j2] = ans + temp ; 
    }
    int cherryPickup(vector<vector<int>>& g) {
        // Your code goes here
        int n = g.size () , m = g[0].size() ; 
        dp.resize(n+5,vector<vector<int>> (m+5,vector <int> (m+5,-1))) ;

        return solve(0,0,m-1,g) ; 
    }
}; 