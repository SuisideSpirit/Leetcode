class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size() ;
        int ans = 0 ;
        int maxi = p[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            ans = max(ans,maxi- p[i]) ; 
            maxi = max(maxi,p[i]) ;
        }
        return ans ;
        
    }
};