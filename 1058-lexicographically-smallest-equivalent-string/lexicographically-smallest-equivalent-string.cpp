class Solution {
public:
    int find(char a , vector <int> &v){
        int pos = (int)(a) - 97 ;
        while(pos != v[pos]){
            pos = v[pos] ; 
        }
        return pos ;
    }
    void update(char a , char b , vector <int> &v){
        int pos1 = find(a,v) ; 
        int pos2 = find(b,v) ; 
        if(pos1 < pos2) v[pos2] = pos1 ;
        else v[pos1] = pos2 ;
    }
    string smallestEquivalentString(string s1, string s2, string str) {
        vector <int> v(26) ; 
        int n = s1.length() ;
        for(int  i= 0 ; i<26;i++){
            v[i] = i ;
        } 
        for(int i= 0 ; i<n ; i++){
            update(s1[i],s2[i],v) ; 
        }
        string ans = "";
        for(int i = 0 ; i < str.length() ; i++){
            int pos = find(str[i],v) ; 
            ans = ans + char(97 + pos) ; 
        }
        return ans; 
    }
};