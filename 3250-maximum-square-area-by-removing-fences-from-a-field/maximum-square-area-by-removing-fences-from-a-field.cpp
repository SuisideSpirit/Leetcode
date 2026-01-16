class Solution {
public:
    void solve(int n, vector<int>& v ,unordered_set <int>& st){
        for(int i = 0 ; i<v.size() ; i++){
            for(int j = i+1 ; j<v.size() ; j++ ){
                st.insert(v[j] - v[i]) ; 
            }
        }
        return ;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1); 
        hFences.push_back(m); 
        vFences.push_back(1); 
        vFences.push_back(n); 
        sort(hFences.begin() , hFences.end()) ; 
        sort(vFences.begin() , vFences.end()) ; 
        int MOD = 1000000007 ;

        unordered_set <int> h , v ;

        solve(m,hFences,h) ;
        h.insert(m-1) ;
        solve(n,vFences , v) ;
        long long ans = 0 ;
        for(auto ele : h){
            if(v.find(ele) != v.end() && ele > ans){
                ans= ele ;
            }
        } 
        if(ans != 0 ) return ((ans%MOD)*(ans%MOD))%MOD;
        return -1 ;
    }
};