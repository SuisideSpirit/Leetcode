class Solution {
public:
    bool cmp(unordered_set <string>& st1 , unordered_set <string>& st2){
        for(auto &ele : st1 ){
            if(st2.find(ele) != st2.end()) return true ;
        }
        return false ;
    }
    int find_parent(int x , vector <int> &parent){
        if(parent[x] == x ) return x ;
        int p = parent[x] ; 
        return parent[x] = find_parent(p,parent) ; 
    }
    void Union(int u , int v ,vector <int> &parent , vector <unordered_set <string>>& mails ){
        int up = find_parent(u,parent) ; 
        int vp = find_parent(v,parent) ; 
        if(up == vp ) return ; 
        if(mails[up].size() >= mails[vp].size()){
            for(auto ele : mails[vp]){
                mails[up].insert(ele) ; 
            }
            parent[vp] = up ;
        }
        else {
            for(auto ele : mails[up]){
                mails[vp].insert(ele) ; 
            }
            parent[up] = vp ;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size() ; 
        vector <unordered_set <string>> mails(n) ; 
        vector <int> parent(n) ;
        for(int i = 0 ; i < n; i++){
            parent[i] = i ;
            for(int j = 1 ; j < accounts[i].size() ; j++){
                mails[i].insert(accounts[i][j]) ; 
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = i +1 ; j< n ; j++){
                int pi = find_parent(i,parent);
                int pj = find_parent(j,parent);

                if(pi == pj) continue;
                if(accounts[i][0] == accounts[j][0] && cmp(mails[i],mails[j]) ){
                    Union(i,j,parent,mails) ; 
                }
            }
        }
        vector <int> visited(n,0) ;  
        vector <vector<string>> ans ; 

        for(int i = 0 ; i < n ;i++){
            int p = find_parent(i,parent) ; 
            if(visited[p] == 1) continue ; 
            visited[p] = 1 ; 
            vector<string> temp(mails[p].begin(), mails[p].end());
            sort(temp.begin(), temp.end());

            vector<string> curr;
            curr.push_back(accounts[p][0]); 

            for(auto &mail : temp){
                curr.push_back(mail);
            }

            ans.push_back(curr);
        }
        return ans ;



        
    }
};