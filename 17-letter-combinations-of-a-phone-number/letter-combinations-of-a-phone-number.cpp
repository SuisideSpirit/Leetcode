class Solution {
public:
    vector <string> ans ; 
    void solve(int idx , string &s,  string curr ,unordered_map<int,vector<char>> &mp){
        if(idx == s.size()){
            ans.push_back(curr) ;
            return ; 
        }
        for(auto ele : mp[s[idx] - '0']){
            string temp = curr + ele ;
            solve(idx +1 , s , curr + ele , mp) ; 
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map <int,vector <char>> mp ; 
        int idx = 0 ; 
        for(int i = 2 ; i < 7 ; i++){
            mp[i].push_back('a' + idx) ; 
            idx++;
            mp[i].push_back('a' + idx) ; 
            idx++;
            mp[i].push_back('a' + idx) ; 
            idx++;
        }
        mp[7] = {'p' , 'q' ,'r' , 's'} ; 
        mp[8] = {'t' , 'u' ,'v'} ;
        mp[9] = {'w' , 'x' ,'y' , 'z'} ; 
        string s = "" ; 
        solve(0 , digits , s ,mp) ; 
        return ans ;

        
    }
};