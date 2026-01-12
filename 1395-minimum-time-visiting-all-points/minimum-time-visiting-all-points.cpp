class Solution {
public:
    int solve(int x1, int y1 , int x2 , int y2){
        int movex = abs(x1 - x2) ; 
        int movey = abs(y1- y2) ;
        return abs(movex - movey) + min(movex,movey) ;
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0 ;

        int currX = points[0][0] ; 
        int currY = points[0][1] ; 
        for(int i = 1 ;i < points.size() ; i++){
            time += solve(currX , currY , points[i][0] , points[i][1]) ; 
            currX = points[i][0]  ;
            currY = points[i][1]  ;
        }
        return time ;
        
    }
};