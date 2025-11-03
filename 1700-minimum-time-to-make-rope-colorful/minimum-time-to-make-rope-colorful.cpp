class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int n = s.length() ; 

        int ans = 0 ;
        for(int i =0 ; i<n-1 ;i++){
            if(s[i] == s[i+1]){
                int maxiT = neededTime[i] ;
                int totT = neededTime[i]; 
                while(i!=n-1 && s[i] == s[i+1]){
                    maxiT = max(maxiT , neededTime[i+1]) ; 
                    totT += neededTime[i+1] ;
                    i++; 
                }
                //cout<<totT<<" "<<maxiT<<endl;
                ans += (totT - maxiT) ; 
            }
        }
        return ans ;
        
    }
};