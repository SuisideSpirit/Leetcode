class Solution {
public:
    bool isTrionic(vector<int>& s) {
        int n = s.size() ;
        int idx = 0 ; 
        if(s[idx] >= s[idx+1]) return false;
        while(idx != n-1 && s[idx] < s[idx+1]) idx++ ;
        cout<<idx<<endl;
        if(idx == n-1 || s[idx] == s[idx+1]) return false;
        while(idx != n-1 && s[idx] > s[idx+1]) idx++ ;
        cout<<idx<<endl;
        if(idx == n-1 || s[idx] == s[idx+1]) return false;
        while(idx != n-1 && s[idx] < s[idx+1]) idx++ ;
        cout<<idx<<endl;
        if(idx != n-1) return false;
        return true;
    }
};