class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size() ;
        int ans = 0 ; 
        for(int i = 0 ; i < k ; i++) ans += v[n-1-i] ; 

        int temp = ans ;
        if(k == n) return ans ; 
        for(int i = 0 ; i < k ;i++ ){
            temp = temp + v[i] - v[n-k + i] ; 
            cout<<v[n-1-k + i]<<endl;
            ans = max(ans,temp) ;
        }
        return ans ;
        
        
    }
};