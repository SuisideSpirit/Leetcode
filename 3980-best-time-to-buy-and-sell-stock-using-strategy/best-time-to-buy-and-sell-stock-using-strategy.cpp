class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long ans =0 ;
        int n = prices.size() ; 
        for(int i =0;i<n ;i++){
            ans += (strategy[i]*prices[i]) ; 
        }
        long long temp = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(i < k ){
                if(i>=k/2) temp += prices[i] ; 
            }
            else temp += (strategy[i]*prices[i]) ; 
        }
        ans = max(temp,ans ) ; 
        
        for(int i = 0 ;i < n-k ; i++){
            temp = temp + (strategy[i]*prices[i]) ;
            temp = temp - prices[i+k/2] ;
            temp = temp - (strategy[i+k]*prices[i+k]) + prices[i+k] ;
            ans = max(temp,ans) ;
            cout<<temp;
        }
        return ans ;
        
    }
};