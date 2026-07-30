class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <pair<int,int>> v; 
        int n = intervals.size() ; 
        for(int i = 0; i < n ; i++){
            v.push_back({intervals[i][0] , intervals[i][1]}) ; 
        }
        sort(v.begin() , v.end()) ; 
        vector <vector<int>> ans ; 
        int st = v[0].first , end= v[0].second  ;
        for(int i = 1 ; i < n ; i++){
            int s = v[i].first, e = v[i].second ; 
            if((s >= st && s <= end) || (e >= st && e <= end) ){
                st = min(s,st) ; 
                end = max(e, end) ; 
            }
            else{
                ans.push_back({st ,end}) ; 
                st = s ;
                end = e ; 
            }
        }
        ans.push_back({st ,end}) ; 
        return ans ;
        
    }
};