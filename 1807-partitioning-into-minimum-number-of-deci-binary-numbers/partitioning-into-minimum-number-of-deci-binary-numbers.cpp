class Solution {
public:
    int minPartitions(string n) {
        int l = n.length();
        int ans = 0 ;
        for (int i = 0 ; i<l ; i++){
            if (ans< ((int)(n[i]) - 48 ) )
                ans = ((int)(n[i]) - 48); 
        }
        return ans ;
        
    }
};