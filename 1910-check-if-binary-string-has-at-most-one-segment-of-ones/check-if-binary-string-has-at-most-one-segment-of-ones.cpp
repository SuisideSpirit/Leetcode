class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size(); 
        int idx = 0 ;
        for(idx = 0 ; idx < n ; idx++){
            if(s[idx] == '0' ) break;
        }
        for(int i = idx; i <n ; i++){
            if(s[i] == '1') return false;
        }
        return true ;
    }
};