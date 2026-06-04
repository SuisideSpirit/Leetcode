class Solution {
public:
    int check(int n){
        string s = to_string(n) ; 
        int ans = 0 ; 
        for(int i = 1 ; i < s.size()-1 ; i++){
            if(s[i] > s[i+1] && s[i] > s[i-1]) ans++;
            else if(s[i] < s[i+1] && s[i] < s[i-1]) ans++ ;
        }
        return ans ;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0 ; 
        for(int i = num1 ; i <= num2 ; i++){
            ans += check(i) ; 
        }
        return ans; 
    }
};