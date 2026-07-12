class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char ,int> mp ; 
        int ans = 0 , n = s.size() , curr = 0 ; 
        for(int i = 0 ; i < n ; i++){
            if(mp.find(s[i]) != mp.end()){
                int idx = mp[s[i]] ;
                cout<<i<<" "<<idx<<endl;
                if(idx >= i - curr) curr = i - (idx +1)  ;
            }
            curr++;
            cout<<s[i]<<" "<<curr<<endl;
            mp[s[i]] = i ; 
            ans = max(ans , curr) ;
        }
        return ans ;
    }
};