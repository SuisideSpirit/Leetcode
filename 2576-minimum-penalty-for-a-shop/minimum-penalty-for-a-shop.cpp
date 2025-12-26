class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length() ; 
        vector <int> pre(n+1) ;
        vector <int> suf(n+1) ;
        pre[0] = 0 ;
        suf[n] = 0 ;
        for (int i = 0 ;i<n ; i++){
            if (customers[i] == 'N') pre[i+1] = pre[i] +1; 
            else pre[i+1] = pre[i] ;
        }
        for (int i = n-1 ;i>=0 ; i--){
            if (customers[i] == 'Y') suf[i] = suf[i+1] +1; 
            else suf[i] = suf[i+1] ;
        }
        vector<int> ans(n+1) ;
        for (int i= 0 ; i<=  n; i++){
            ans [i] = pre[i] + suf[i] ;
        }
        int min =ans[0];
        for (int i = 0 ; i<= n ; i++){
            if (ans[i]<min) min = ans[i];
        }
        for (int i = 0 ; i<= n ; i++){
            if (ans[i] == min) return i  ;
        }
        return 1 ;
    }
};