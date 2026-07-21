class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n =s.size() ;
        vector <pair<int,int>> v;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0'){
                int temp = 1 ;
                int st = i ; 
                int end = i + 1 ;
                while(end < n && s[end] == '0'){
                    end++ ;
                }
                v.push_back({st , end}) ; 
                //cout<<st<<" "<<end<<endl;
                i = end -1 ;
            }
            else ans++ ; 
        }
        int biggest = 0 ;
        int m = v.size() ;
        for(int i = 0 ; i < m - 1 ; i++){
            int st1 = v[i].first , end1 = v[i].second ; 
            int st2 = v[i+1].first , end2 = v[i+1].second ; 
            biggest = max(end2 - st1 - st2 + end1, biggest) ; 
            //cout<<biggest<<endl;
        }
        return ans + biggest ; 


        
    }
};