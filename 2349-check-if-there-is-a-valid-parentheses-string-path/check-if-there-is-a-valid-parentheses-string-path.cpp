class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        queue <pair<int,pair<int,int>>> q ; 
        if(grid[0][0] == ')') return false ;
        q.push({0,{0,0}}) ;
        vector <vector<vector<int>>> visit(n , vector<vector<int>> (m , vector <int> (200 , 0))) ; 
        while(q.size() != 0){
            int size = q.size() ; 
            while(size--){
                auto ele = q.front() ; 
                int op = ele.first , x = ele.second.first , y = ele.second.second ;
                q.pop();
                if(visit[x][y][op] != 0) continue ; 
                visit[x][y][op] = 1 ; 
                if(grid[x][y] == '(') op++ ;
                else op--;
                if(op < 0) continue ; 
                if(x == n-1 && y == m-1 ){
                    if(op == 0) return true ; 
                    continue ; 
                }
                if(x != n-1) q.push({op ,{x + 1 ,y}}) ; 
                if(y != m-1) q.push({op ,{x , y +1}}) ;
            }
        }
        return false ;
        
    }
};