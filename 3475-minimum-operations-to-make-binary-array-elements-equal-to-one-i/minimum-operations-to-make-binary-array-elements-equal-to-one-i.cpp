class Solution {
public:
    int minOperations(vector<int>& v) {
        int n = v.size() ; 
        int ans = 0 ;
        for(int i =0 ; i<n-2 ; i++){
            if(v[i] == 0){
                v[i] = 1 ;
                if(v[i+1] == 1 ) v[i+1] = 0 ;
                else v[i+1] = 1 ;
                if(v[i+2] == 1 ) v[i+2] = 0 ;
                else v[i+2] = 1 ;
                ans++;
            }
        }
        if(v[n-1] == 0 || v[n-2] == 0) return -1 ;
        return ans ;
    }
};