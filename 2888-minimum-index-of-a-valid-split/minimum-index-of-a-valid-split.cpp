class Solution {
public:
    int minimumIndex(vector<int>& v) {
        int n = v.size() ; 
        int dom = -1;
        unordered_map <int,int> mp ;
        for(int i =0 ; i< n; i++){
            mp[v[i]]++;
        }
        for(auto ele :mp){
            if(ele.second > n/2 ) dom = ele.first;
        }
        int fpart = 0 ;
        int spart = n ;
        int fdom = 0 ;
        int sdom = mp[dom] ; 
        int ans = -1 ;
        for(int i = 0 ; i<n-1 ; i++){
            fpart += 1 ;
            spart -= 1 ;
            if(v[i] == dom) {
                fdom +=1 ;
                sdom -= 1 ;
            }
            if(fdom > fpart/2 && sdom > spart/2){
                ans = i ;
                break ;
            }
        }
        return ans ;
    }
};