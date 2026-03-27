class Solution {
public:
    typedef pair<int,int> pp ; 
    int orangesRotting(vector<vector<int>>& v) {
        queue <pp> q ; 
        int n = v.size() ;
        int m = v[0].size() ;
        int notRotten = 0 ;
        for(int i =0  ; i <n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(v[i][j] == 2) q.push({i,j}) ; 
                if(v[i][j] == 1) notRotten += 1; 
            }
        }
        int time = 0 ;
        if(notRotten == 0) return 0 ;  
        while(q.size() != 0){
            time++;
            int size = q.size() ;
            while(size--){
                pp curr = q.front() ; 
                q.pop() ;
                int x = curr.first ; 
                int y = curr.second ;

                if(x!= n-1 && v[x+1][y] == 1){
                    notRotten--;
                    q.push({x+1,y}) ;
                    v[x+1][y] = 2 ;
                }
                if(x!= 0 && v[x-1][y] == 1){
                    notRotten--;
                    q.push({x-1,y}) ;
                    v[x-1][y] = 2 ;
                }
                if(y!= 0 && v[x][y-1] == 1){
                    notRotten--;
                    q.push({x,y-1}) ;
                    v[x][y-1] = 2 ;
                }
                if(y!=m-1 && v[x][y+1] == 1){
                    notRotten--;
                    q.push({x,y+1}) ;
                    v[x][y+1] = 2 ;
                }
                if(notRotten == 0) return time ;
            }
        }
        return -1 ;


        
    }
}; 