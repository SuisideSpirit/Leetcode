class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map <char,int> mp1 , mp2;
        int n = s1.size() ;
        for(int i = 0 ;i < n; i++){
            if(i%2 == 0) mp1[s1[i]]++;
            else mp2[s1[i]]++;
        }
        for(int i = 0; i < n ; i++){
            if(i%2 ==0){
                if(mp1[s2[i]] == 0) return false; 
                else mp1[s2[i]]-- ;
            }
            else{
                if(mp2[s2[i]] == 0) return false; 
                else mp2[s2[i]]-- ;
            }
        }
        for(auto &ele :mp1){
            if(ele.second != 0) return false; 
        }
        for(auto &ele :mp2){
            if(ele.second != 0) return false; 
        }

        return true ;
    }
};