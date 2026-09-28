class Solution {
public:
    int evalRPN(vector<string>& s) {
        int n = s.size() ; 
        stack <int> st ;
        for(int i = 0;  i < n ; i++){
            if(s[i] == "+"){
                int a = st.top() ; 
                st.pop() ; 
                int b = st.top() ; 
                st.pop() ; 
                st.push(a+b) ;
            }
            else if(s[i] == "-"){
                int a = st.top() ; 
                st.pop() ; 
                int b = st.top() ; 
                st.pop() ; 
                st.push(b-a) ;
            }
            else if(s[i] == "*"){
                int a = st.top() ; 
                st.pop() ; 
                int b = st.top() ; 
                st.pop() ; 
                st.push(a*b) ;
            }
            else if(s[i] == "/"){
                int a = st.top() ; 
                st.pop() ; 
                int b = st.top() ; 
                st.pop() ; 
                st.push(b/a) ;
            }
            else{
                int a = stoi(s[i]) ; 
                st.push(a) ;
            }
        }
        return st.top();
        
    }
};