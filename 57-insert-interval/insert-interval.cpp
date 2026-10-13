class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval) ;
        sort(intervals.begin() , intervals.end()) ;
        vector <vector<int>> ans ;
        for(int i =0  ; i < intervals.size() ; i++){
            int st = intervals[i][0] , end = intervals[i][1] ;
            int idx = i + 1; 
            while(idx < intervals.size() && intervals[idx][0] <= end){
                end = max(end , intervals[idx][1]) ; 
                idx++ ; 
            } 
            ans.push_back({st,end}) ;
            i = idx -1 ;
        }
        return ans ;
        
    }
};