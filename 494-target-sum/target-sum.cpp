class Solution {
public:
    vector <vector<int>> dp ;
    int extra = 2500 ;
    int solve(int i , vector<int>& v, int target){
        int n = v.size() ; 
        if(i==n && target == 0) return 1 ;
        if (i >= n ) return 0 ;
        if(dp[i][target+extra] != -1) return dp[i][target+extra] ;

        int add = solve(i+1,v,target-v[i]) ; 
        int sub = solve(i+1,v,target+v[i]) ; 

        return dp[i][target+extra] = add + sub ;

    }
    int findTargetSumWays(vector<int>& v, int target) {
        int n = v.size() ;
        dp.resize(n+5,vector<int> (5000,-1)) ; 
        return solve(0,v,target) ; 
    }
}; 