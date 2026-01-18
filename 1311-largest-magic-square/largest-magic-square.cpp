class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Prefix sums for rows, columns
        vector<vector<int>> row(n, vector<int>(m, 0));
        vector<vector<int>> col(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i][j] = grid[i][j] + (j > 0 ? row[i][j - 1] : 0);
                col[i][j] = grid[i][j] + (i > 0 ? col[i - 1][j] : 0);
            }
        }

        int ans = 1;

        // Try every top-left corner
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Max possible side length
                int maxSide = min(n - i, m - j);

                for (int side = 1; side <= maxSide; side++) {
                    int target = row[i][j + side - 1] - (j > 0 ? row[i][j - 1] : 0);
                    bool valid = true;

                    // Check all rows
                    for (int r = i; r < i + side; r++) {
                        int sumRow = row[r][j + side - 1] - (j > 0 ? row[r][j - 1] : 0);
                        if (sumRow != target) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    // Check all columns
                    for (int c = j; c < j + side; c++) {
                        int sumCol = col[i + side - 1][c] - (i > 0 ? col[i - 1][c] : 0);
                        if (sumCol != target) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    // Check main diagonal
                    int diag1 = 0;
                    for (int k = 0; k < side; k++) diag1 += grid[i + k][j + k];
                    if (diag1 != target) continue;

                    // Check anti-diagonal
                    int diag2 = 0;
                    for (int k = 0; k < side; k++) diag2 += grid[i + k][j + side - 1 - k];
                    if (diag2 != target) continue;

                    ans = max(ans, side);
                }
            }
        }
        return ans;
    }
};
