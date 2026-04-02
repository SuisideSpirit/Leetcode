class Solution {
public:
    vector <vector<vector<long>>> mp ;
    long solve(long i ,long j , long k ,vector<vector<int>>& v){
        long n = v.size() ; 
        long m = v[0].size() ; 
        
        if(i == n-1 && j == m-1){
            if(v[i][j] < 0 && k > 0) return 0; 
            else return v[i][j] ;
        } 
        if(i >= n || j >= m ) return INT_MIN ;
        if (mp[i][j][k] != INT_MIN ) return mp[i][j][k] ;

        long take = 0 , leave = INT_MIN ;

        take = max(solve(i+1,j,k,v) ,solve(i,j+1,k,v)) + v[i][j] ;
        if(v[i][j] < 0 && k > 0 ) leave = max(solve(i+1,j,k-1,v) ,solve(i,j+1,k-1,v)) ;

        return mp[i][j][k] = max(take,leave) ;
    }
    int maximumAmount(vector<vector<int>>& coins){
        long n = coins.size() ; 
        long m = coins[0].size() ; 
        mp.resize(n+5 , vector <vector<long>> (m+5 , vector <long> (3,INT_MIN))) ; 
        return solve(0,0,2,coins) ;
    }
};