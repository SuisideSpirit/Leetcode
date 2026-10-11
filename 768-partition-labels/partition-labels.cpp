class Solution {
public:
    int traverse(int st , int end ,string &s, unordered_map <char,int> &mp){
        for(int i = st ; i < end ; i++){
            end = max(end , mp[s[i]]) ; 
        }
        return end ;
    }
    vector<int> partitionLabels(string s) {
        int n = s.size() ; 
        unordered_map <char,int> mp ;   
        for(int i = 0 ; i < n ; i++){
            mp[s[i]] = i ; 
        }
        vector <int> ans ;
        for(int idx = 0 ; idx < n ; idx++){
            int st = idx ; 
            int end = mp[s[idx]] ; 
            idx = traverse(st, end ,s , mp) ; 
            ans.push_back(idx - st  +1) ; 
        }
        return ans ;

        
    }
};