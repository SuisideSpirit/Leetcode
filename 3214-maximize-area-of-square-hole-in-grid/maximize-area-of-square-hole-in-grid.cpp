class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // hBars.push_back(n+2) ; 
        // vBars.push_back(m+2) ;
        sort(hBars.begin(),hBars.end()) ;
        sort(vBars.begin(),vBars.end()) ;

        int maxH = 0 ;
        for(int i =0 ; i<hBars.size() ; i++){
            int start = hBars[i] -1 ; 
            int end = hBars[i]-1 ; 
            while(i<hBars.size() && hBars[i] == end + 1){
                end = hBars[i] ;
                i++;
            }
            i--;
            cout<<start<<" "<<end<<endl;
            maxH = max(maxH , end - start+ 1) ; 
        }
        int maxV = 0 ;
        for(int i =0 ; i<vBars.size() ; i++){
            int start = vBars[i] -1 ; 
            int end = vBars[i]-1 ; 
            cout<<vBars[i]<<endl;
            while(i<vBars.size() && vBars[i] == end + 1){
                end = vBars[i] ;
                i++;
            }
            i--;
            cout<<start<<" "<<end<<endl;
            maxV = max(maxV , end - start + 1) ; 
        }
        cout<<maxH<<" "<<maxV<<endl;
        int ans = min(maxH , maxV) ;
        return ans*ans ; 
    }
};