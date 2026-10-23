class Solution {
public:
    bool isNStraightHand(vector<int>& v,  int size) {
        map <int,int> mp ;
        int n = v.size() ; 
        if(n%size != 0) return false;
        for(int i = 0 ; i < n ; i++){
            mp[v[i]]++; 
        }
        int count = 0 ; 
        while(count != n){
            int prev = -1 ;
            int s = 0 ;
            for(auto ele : mp ){
                if(s >= size) break ;
                if(prev != -1 && prev +1 != ele.first) return false ;
                prev = ele.first ;
                mp[prev]-- ; 
                if(mp[prev] == 0) mp.erase(ele.first) ;  
                s++;
            }
            if(s != size) return false; 
            count += size; 
        }
        return true;
        
    }
};