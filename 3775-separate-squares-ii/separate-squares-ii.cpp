class Solution {
public:
    struct Event{
        int y ; 
        int type ; 
        int x1 , x2 ;

        bool operator<(const Event& other) const{
            return  y < other.y ;
        }
    };
    double getUnionWidth(vector <pair<int,int>> intervals){
        if(intervals.size() == 0 ) return 0.0 ;

        sort(intervals.begin(),intervals.end()) ;
        double width = 0 ;
        int currL = intervals[0].first ;
        int currR = intervals[0].second ; 

        for(int i = 1; i < intervals.size() ; i++){
            if(intervals[i].first > currR){
                width += currR - currL ; 
                currL = intervals[i].first ;
                currR = intervals[i].second ;
            }
            else currR = max(intervals[i].second,currR) ;
        }
        width += currR  - currL ; 
        return width ;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size() ; 
        
        vector <Event> events ; 
        for(auto &s : squares){
            int x = s[0] ;
            int y = s[1] ;
            int l = s[2] ;

            events.push_back({y,1,x,x+l}) ; 
            events.push_back({y+l,-1,x,x+l}) ;
        }
        sort(events.begin() , events.end()) ; 

        vector <pair<int,int>> activeX ; 
        vector <tuple<int,int,double>> strips ; 

        double totalA = 0.0 ;
        int prevY = events[0].y ; 

        for(auto &e : events){
            if(e.y > prevY){
                double width = getUnionWidth(activeX) ; 
                int height = e.y - prevY ; 
                if(width > 0){
                    strips.push_back({prevY , height , width} ) ;
                    totalA += width*height;
                } 
            }
            if(e.type == +1){
                activeX.push_back({e.x1,e.x2}) ;
            }
            else {
                for(auto it = activeX.begin() ; it != activeX.end() ; it++ ){
                    if(it->first == e.x1 && it->second == e.x2  ){
                        activeX.erase(it) ;
                        break ;
                    }
                }
            }
            prevY = e.y ;

        }
        double target = totalA/2.0;     
        double currA = 0.0 ; 

        for(auto &strip : strips){
            int y , h ; 
            double w ;
            tie(y,h,w) = strip ; 

            double SA = w*h ; 

            if(SA + currA >= target){
                double need = target - currA ; 
                return y + (need/w) ; 
            }
            currA += SA ;
        }
        return 0.0 ;
        
    }
}; 