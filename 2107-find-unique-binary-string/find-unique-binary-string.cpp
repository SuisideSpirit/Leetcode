class Solution {
public:
    int to_decimal(string &s){
        int ans = 0 ;
        int mult = 1 ; 
        for(int i = s.size() - 1 ; i >=0  ;i--){
            if(s[i] == '1') ans += mult ;
            mult *= 2 ;
        }
        return ans ;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        vector <int> v; 
        int n = nums.size() ; 
        for(int i = 0 ; i < n ; i++){
            v.push_back(to_decimal(nums[i])) ; 
        }
        sort(v.begin(),v.end()) ; 
        int ans = n ;
        for(int i= 0 ; i < n ;i++){
            if(v[i] != i) {
                ans = i ;
                break ;
            }
        }
        string s = "" ; 
        while(ans > 0){
            if(ans%2 == 0) s = '0' + s ;
            else s = '1' + s ;
            ans/=2 ;
        }
        while(s.size() != nums[0].size()){
            s  = '0' + s ;
        }
        return s;
        
    }
};