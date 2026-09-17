class Solution {
public:
    int dp[100005][2][2];

    int solve(int idx, int buy, int t, vector<int>& prices) {
        int n = prices.size();

        if (idx == n || t == 2)
            return 0;

        if (dp[idx][buy][t] != -1)
            return dp[idx][buy][t];

        // Don't do anything today
        int leave = solve(idx + 1, buy, t, prices);

        int take;

        if (buy) {
            // Buy today
            take = -prices[idx] + solve(idx + 1, 0, t, prices);
        }
        else {
            // Sell today
            take = prices[idx] + solve(idx + 1, 1, t + 1, prices);
        }

        return dp[idx][buy][t] = max(leave, take);
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0, prices);
    }
};