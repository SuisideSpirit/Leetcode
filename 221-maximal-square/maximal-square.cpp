class Solution {
public:
    int solve(int i,int j ,vector<vector<char>>& v,vector<vector<int>>& dp ){
        if(i >= v.size() || j >= v[0].size() || v[i][j] == '0') return 0 ;
        if(dp[i][j] != -1) return dp[i][j] ; 

        int right = solve(i,j+1,v,dp) ; 
        int down = solve(i+1,j,v,dp) ; 
        int dia = solve(i+1,j+1,v,dp) ; 

        return dp[i][j] = 1+min(right,min(down,dia)) ;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 

        vector <vector<int>> dp(n,vector<int> (m,-1)) ; 
        int ans = 0; 
        for(int i = 0; i < matrix.size() ; i++){
            for(int j = 0 ;j<matrix[0].size() ; j++){
                if(matrix[i][j] == '1') ans = max(ans,solve(i,j,matrix,dp)) ; 
            }
        }
        return ans*ans;
    }
};