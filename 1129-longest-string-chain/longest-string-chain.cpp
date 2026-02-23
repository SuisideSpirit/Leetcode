class Solution {
public:
    vector<vector<int>> dp;
    bool check(string &a , string &b){

        int n = a.size() ; 
        int m = b.size() ;
        if(m != n+1) return false;
        int idx1 = 0 , idx2 = 0 ;
        int change = 0 ;
        while(idx1 < n && idx2 < n+1){
            if(a[idx1] != b[idx2]){
                if(change == 0){
                    change = 1 ; 
                    idx2++ ;
                }
                else return false;
            }
            else{
                idx1++;
                idx2++;
            }
        }
        return true;
    }
    int solve(int i , int p ,vector<string>& v){
        int n = v.size() ;
        if(i >= n) return 0 ; 
        if(dp[i][p] != -1) return dp[i][p] ; 
        int take , leave ;
        if(p == i) leave = solve(i+1,i+1,v) ; 
        else leave = solve(i+1,p,v) ;

        if(p != i && v[p].size() + 1 != v[i].size()) take = 0 ;
        else if(p == i || check(v[p],v[i]) ) take = 1 + solve(i+1,i,v) ; 
        else take = 0 ;

        return dp[i][p] = max(take,leave) ;
    }
    int longestStrChain(vector<string>& v) {
        int n = v.size() ; 
        dp.resize(n+5,vector <int> (n+5 , -1)) ; 
        sort(v.begin(), v.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        return solve(0,0,v) ;
    }
};