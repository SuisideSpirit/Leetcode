class Solution {
public:
    int find_parent(int curr , vector <int> &parent){
        if(parent[curr] == -1) return -1 ;
        if(parent[curr] == curr) return curr ; 
        return parent[curr] = find_parent(parent[curr] , parent) ; 
    }
    void Union(int u , int v , vector<int> &parent , vector <int> & size){
        int pu = find_parent(u , parent) ; 
        int pv = find_parent(v , parent) ; 
        if(pu == pv) return ; 
        if(size[pu] > size[pv]){
            size[pu] += size[pv] ; 
            parent[pv] = pu ; 
        }
        else{
            size[pv] += size[pu] ; 
            parent[pu] = pv ; 
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector <pair<int ,int>> check; 
        vector <int> parent(26) , size(26,1) ; 
        for(int i = 0 ; i < 26 ; i++){
            parent[i] = -1 ; 
        }
        for(auto ele : equations){
            char a = ele[0] , b =ele[3] , c = ele[1] ; 
            int A = a - 'a' , B = b - 'a' ;
            if(parent[A] == -1) parent[A] = A ;
            if(parent[B] == -1) parent[B] = B ;
            if(c == '!'){
                check.push_back({A , B}) ; 
                continue ;
            }
            Union(A , B , parent , size) ; 
        }
        for(auto ele : check){
            int x= ele.first , y = ele.second ; 
            int px = find_parent(x ,parent) ; 
            int py = find_parent(y , parent) ; 
            if(px == -1 || py == -1) continue ;
            if(px == py){
                return false ;
            }
        }
        return true ; 
        
    }
};