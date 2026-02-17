class Solution {
public:
    int onDigit(int n){
        int c = 0;
        while(n > 0){
            if(n%2 == 1) c++ ;
            n /= 2 ;
        }
        return c ;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector <string> ans; 
        for(int i = 0 ; i < 12 ;i++){
            for(int j = 0 ; j<60; j++){
                if(onDigit(i) + onDigit(j) == turnedOn){
                    if(j < 10) ans.push_back(to_string(i) + ":0" + to_string(j)) ;
                    else ans.push_back(to_string(i) + ":" + to_string(j)) ;
                }
            }
        }
        return ans ;
        
    }
};