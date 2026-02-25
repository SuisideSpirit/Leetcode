class Solution {
public:
    int get_bits(int n ){
        int c = 0 ; 
        while(n>0){
            if(n%2 != 0 ) c++;
            n/=2 ;
        }
        return c ;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> mp(32);
        int n = arr.size() ;
        sort(arr.begin() ,arr.end()) ;
        for(int i = 0 ; i < n ;i++){
            int c = get_bits(arr[i]) ; 
            mp[c].push_back(arr[i]) ;
        }
        vector <int> ans ;
        for(int i = 0 ; i < 32 ;i++){
            for(int j = 0 ; j<mp[i].size() ; j++){
                ans.push_back(mp[i][j]) ;
            }
        }
        return ans ;
    }
};