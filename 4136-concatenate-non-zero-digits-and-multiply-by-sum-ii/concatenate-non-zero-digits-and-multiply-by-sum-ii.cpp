class Solution {
public:
    int MOD =1e9 + 7 ; 
    vector <long long> pow10 ;
    long long compute(long long curr ,long long prev ,long long len1 , long long len2){
        prev = (prev%MOD * pow10[len1 - len2]%MOD)%MOD  ; 
        return (curr - prev  + MOD)%MOD; 
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int n = s.size() ;
        vector <long long> prefix_sum(n) ;
        vector <long long> prefix_val(n) ;
        vector <long long> non_zero_digit(n) ; 
        pow10.resize(n+1) ;
        pow10[0] =1 ;
        long long val = 0 ; 
        long long sum = 0 ;
        long long dig = 0 ;
        for(int i =0 ; i<n ; i ++){
            long long rem =  (int)(s[i] - '0') ;
            sum += rem ;
            if(s[i] != '0' ){
                val = (val*10%MOD + rem%MOD)%MOD;
                dig++;
            }
            prefix_sum[i] = sum ; 
            prefix_val[i] = val ;
            non_zero_digit[i] = dig ;
            if(i!=0)pow10[i] = (pow10[i-1]*10 )%MOD;
        }

        vector <int> ans ;
        for(int i = 0 ; i < q.size() ; i++){
            int st = q[i][0] ;
            int end = q[i][1] ;
            if(st == 0){
                int a = (prefix_sum[end]%MOD * prefix_val[end]%MOD)%MOD ;
                ans.push_back(a) ; 
            }
            else{
                sum = prefix_sum[end] - prefix_sum[st-1] ; 
                val = compute(prefix_val[end], prefix_val[st-1],non_zero_digit[end] ,non_zero_digit[st-1]);
                int a = ((sum%MOD) * (val%MOD))%MOD ;
                ans.push_back(a) ;
            }
        }
        return ans ;
        
    }
}; 