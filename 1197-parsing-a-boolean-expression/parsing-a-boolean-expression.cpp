class Solution {
public:
    bool parseBoolExpr(string s) {
        stack <char> st  ;
        int n = s.length() ;

        for(int i = 0 ; i<n ;i++){
            if(s[i] == ',') continue ;
            if(s[i] != ')') st.push(s[i]) ; 
            if(s[i] == ')'){
                int t = 0 , f = 0 ;
                while(st.top() != '('){
                    if(st.top() == 't') t++; 
                    else f++ ;
                    st.pop()  ;
                }
                st.pop() ; 
                if(st.top() == '!'){
                    st.pop() ; 
                    if(t != 0) st.push('f') ; 
                    else st.push('t') ;
                }
                else if(st.top() == '&'){
                    st.pop() ; 
                    if(f != 0) st.push('f') ; 
                    else st.push('t') ;
                }
                else if(st.top() == '|'){
                    st.pop() ; 
                    if(t == 0) st.push('f') ; 
                    else st.push('t') ;
                }
                
            }
        }
        if(st.top() =='t') return true ;
        return false ;
    }
};