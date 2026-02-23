class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length() ; 
        unordered_set <string> st ; 
        string curr = s.substr(0,k) ; 
        cout<<curr<<endl;
        st.insert(curr) ; 
        for(int i = k ; i < n ; i++){
            curr.erase(0,1) ; 
            curr = curr + s[i] ; 
            st.insert(curr) ; 
        }
        if(st.size() == 1<<k) return true ; 
        return false;        
    }
};