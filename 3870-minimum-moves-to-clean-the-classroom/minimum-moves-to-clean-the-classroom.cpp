class Solution {
public:
    int minMoves(vector<string>& v, int energy) {
        int n = v.size() ; 
        int m = v[0].size() ;
        int sx = 0 , sy = 0 ,c = 0 ;
        int ans = 0 ; 
        unordered_map <string,int> mp ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(v[i][j] == 'S'){
                    sx = i ; 
                    sy = j ; 
                }
                if(v[i][j] == 'L'){
                    string s = to_string(i) + "_" +to_string(j) ; 
                    mp[s] = c ;
                    ans += (1 << c) ; 
                    c++;
                } 
            }
        }

        vector<vector<vector<int>>> states(n+5,vector <vector<int>> (m +5 , vector<int> (1<<c,INT_MIN))) ;
        queue <pair<pair<int,int> ,pair<int,int>>> q ;
        q.push({{sx , sy} , {energy , 0}}) ; 
        int steps= -1 ; 
        vector <pair<int,int>> moves = {{1, 0} , {-1, 0} , {0,-1} , {0,1}} ; 
        while(q.size() != 0){
            int s = q.size() ; 
            steps++ ;
            while(s--){
                auto ele = q.front() ; 
                int x = ele.first.first, y = ele.first.second ; 
                int e = ele.second.first ,mask = ele.second.second ;
                q.pop() ;
                if(v[x][y] == 'R') e = energy ;
                if(v[x][y] == 'L'){
                    string s = to_string(x) + "_" +to_string(y) ; 
                    int pos = mp[s] ; 
                    mask |= (1 << pos);  
                }
                if(mask == ans) return steps ; 
                for(int i = 0 ; i < 4 ; i++){
                    int nx = x + moves[i].first ; 
                    int ny = y + moves[i].second ; 
                    if(nx < n && nx >= 0 && ny >= 0 && ny < m && v[nx][ny] != 'X'){
                        if(e - 1 >= 0 && states[nx][ny][mask] < e -1 ){
                            states[nx][ny][mask] =  e - 1 ; 
                            q.push({{nx , ny} , {e -1 , mask}}) ; 
                        }
                    }
                }
            }
        }
        return -1 ; 

    }
};