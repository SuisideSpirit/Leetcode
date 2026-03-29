class Solution {
public:
    bool similarity(string a , string b){
        int n = a.size() ; 
        bool flag = true ;
        for(int i = 0 ; i < n ; i++){
            if(flag && a[i] != b[i]) flag = false; 
            else if(flag == false && a[i] != b[i]) return false ;
        }
        return true ;
    }
    int ladderLength(string start, string end, vector<string>& words) {
        int n = words.size() ; 
        unordered_map <string,vector <string>> mp ; 
        bool flag = false ; 
        for(int i = 0 ; i < n ; i++){
            if( words[i] == start) flag = true ;
        }
        if(!flag) words.push_back(start) ;

        for(int i = 0 ; i < words.size() ; i++){
            for(int j = i+1 ; j < words.size() ;j++){
                if(similarity(words[i] , words[j]) && i != j ){
                    mp[words[i]].push_back(words[j]) ; 
                    mp[words[j]].push_back(words[i]) ; 
                }
            }
        }     
        queue <string> q ;
        int ans = 1 ;
        q.push(start) ;  
        unordered_set <string> st ;
        while(q.size() != 0 ){
            int size = q.size() ; 
            ans++;
            while(size--){
                string curr = q.front() ; 
                st.insert(curr)  ;
                q.pop() ;
                //cout<<curr<<" : ";
                for(auto &ele : mp[curr]){
                    //cout<<ele<<" ";
                    if(ele == end) return ans ;
                    if(st.find(ele) == st.end()){
                        q.push(ele) ;
                    }
                }
                cout<<endl;
            }
        }
        return 0 ;



        
    }
};