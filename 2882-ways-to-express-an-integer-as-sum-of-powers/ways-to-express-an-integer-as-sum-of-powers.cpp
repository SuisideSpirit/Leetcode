class Solution {
public:
    vector<vector<long long>> dp;

    long long ipow(int base, int exp) {
        long long result = 1;
        while (exp > 0) {
            result *= base;
            exp--;
        }
        return result;
    }

    long long solve(int n, int curr, int x) {
        if (n == 0) return 1;      
        if (n < 0) return 0;       
        if (curr <= 0) return 0;   

        if (dp[n][curr] != -1) return dp[n][curr];

        long long leave = solve(n, curr - 1, x);

        long long take = 0;
        if (ipow(curr, x) <= n) {
            long long rem = n - ipow(curr, x);
            take = solve(rem, curr - 1, x);
        }

        return dp[n][curr] = leave + take;
    }

    int numberOfWays(int n, int x) {
        dp.assign(n + 1, vector<long long>(n + 1, -1));
        return solve(n, n, x) % 1000000007;
    }
};
