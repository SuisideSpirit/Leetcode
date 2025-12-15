class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size() ;
        long long ans = 0 ; 

        for(int i =0 ;i<n ;i++){
            long long len = 1;
            i++ ; 
            while(i < n && prices[i-1] - 1 == prices[i]){
                i++; 
                len++;
            }
            i--;
            //cout<<len<<endl;
            ans += (len*(len+1))/2 ;
        }
        return ans ;
        
    }
};