class Solution {
public:
    string reverseParentheses(string s) {
        stack <char> st ;
        queue <char> store ;
        for (int i = 0 ;i< s.length() ; i++){
            if (s[i] == '(') st.push(s[i]) ;
            else if (s[i] == ')'){
                while (st.top() != '('){
                    store.push(st.top()) ;
                    st.pop() ;
                }
                st.pop();
                while (store.size()>0){
                    st.push(store.front()) ;
                    store.pop() ;
                }
            }
            else st.push(s[i]) ;
        }
        string ans = "" ;
        while (st.size()>0){
            ans = st.top() + ans ;
            st.pop() ;
        }
        return ans ;

    }
};