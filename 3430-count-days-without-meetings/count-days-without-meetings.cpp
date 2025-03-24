class Solution {
public:
    int countDays(int days, vector<vector<int>>& meeting) {
        vector <pair<int,int>> v ;
        for(int i =0 ;i <meeting.size() ; i++){
            v.push_back({meeting[i][0],meeting[i][1]}) ; 
        }
        sort(v.begin(),v.end()) ; 
        int start = 1 ;
        int end = -1; 
        int ans = 0 ;
        for(int i =0 ; i<v.size() ; i++){
            if(i == 0 ){
                if(v[i].first > 1){
                    ans += (v[i].first - 1) ;
                }
                start = v[i].first ; 
                end = v[i].second ; 
            }
            else {
                if(v[i].first <= end+1){
                    end = max(end,v[i].second) ;
                }
                else {
                    ans += (v[i].first - end - 1) ; 
                    end = max(end,v[i].second) ;
                }
            }
        }
        if(end != days){
            ans += (days - end) ;
        }
        return ans ;
        
        
    }
};