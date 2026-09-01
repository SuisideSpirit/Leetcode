class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector <vector<int>> ans(n , vector<int> (n)) ; 
        int c = 1 ; 
        int maxR = n-1 , minR = 0 ;
        int maxC = n-1 , minC = 0 ; 
        while(maxR >= minR && maxC >= minC){
            for(int i = minC ; i <= maxC ; i++){
                ans[minR][i] = c ; 
                c++ ;
            }
            minR++ ; 
            for(int i = minR ; i <= maxR ; i++){
                ans[i][maxC] = c ; 
                c++ ;
            }
            maxC-- ; 
            for(int i = maxC; i >= minC ; i--){
                ans[maxR][i] = c ; 
                c++ ;
            }
            maxR-- ; 
            for(int i = maxR ; i >= minR ; i--){
                ans[i][minC] = c ; 
                c++ ;
            }
            minC++ ; 
        }
        return ans ; 
    }
};