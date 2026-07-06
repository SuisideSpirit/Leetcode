class Solution {
public:
    vector <int> dp ; 
    bool solve(int idx,string s ,unordered_map <char,vector<string>> & mp){
        int n = s.size(); 
        if(idx == n) return true ; 
        if(idx > n ) return false ;
        if(dp[idx] != -1 ) return dp[idx] ; 
        bool ans = false ;
        for(auto ele : mp[s[idx]]){
            int j = idx ;
            bool flag = true ;
            if(ele.size() > s.size() - idx + 1) continue ; 
            for(int i = 0 ; i < ele.size() ; i++){
                if(s[j] != ele[i] ){
                    flag = false ;
                    break ; 
                }
                j++;
            }

            if(flag){
                bool temp = solve(idx + ele.size() , s, mp) ;
                //cout<<idx<<" "<<j<<" "<<temp<<endl;
                ans = temp || ans ; 
            }
        }
        return dp[idx] = ans ;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size() ;
        dp.resize(n,-1) ; 
        unordered_map <char,vector<string>> mp ; 
        for(auto ele : wordDict){
            mp[ele[0]].push_back(ele) ; 
        }
        return solve(0 , s, mp) ;
        
    }
};