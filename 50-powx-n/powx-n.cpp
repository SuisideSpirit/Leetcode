class Solution {
public:
    double solve(double x , long long pow ){
        if(pow == 0 ) return 1 ;
        if(pow == 1) return x ;
        double temp = x * x ; 
        if(pow%2 == 0 ) return solve(temp , pow/2) ; 
        else return solve(temp , pow/2) * x ; 
    }
    double myPow(double x, int n) {
        long long t = n ; 
        if(n < 0) return solve(1/x , -t) ;
        else  return solve(x , t) ; 
    }
};