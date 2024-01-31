class Solution {
public:
    // Space Optimized Solution
    long long spaMinSum(vector<vector<int>>& grid, int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> prev(n,0);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n,0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = grid[0][0];
                    continue;
                }
                long long up = INT_MAX;
                if (i - 1 >= 0)
                    up = grid[i][j] + prev[j];

                long long left = INT_MAX;
                if (j - 1 >= 0)
                    left = grid[i][j] + temp[j-1];

                temp[j] = min(up, left);
            }
            prev = temp;
        }
        return prev[n - 1];
    }
    // Tabulation (Bottom-Up Solution)
    long long tabMinSum(vector<vector<int>>& grid, int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                    continue;
                }
                long long up = INT_MAX;
                if (i - 1 >= 0)
                    up = grid[i][j] + dp[i - 1][j];

                long long left = INT_MAX;
                if (j - 1 >= 0)
                    left = grid[i][j] + dp[i][j - 1];

                dp[i][j] = min(up, left);
            }
        }
        return dp[m - 1][n - 1];
    }
    // Memoization (Top Down Solution)
    long long memMinSum(vector<vector<int>>& grid, vector<vector<int>>& dp,
                        int m, int n) {
        if (m == 0 && n == 0) {
            return grid[m][n];
        }
        if (m < 0 || n < 0) {
            return INT_MAX;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        long long up = grid[m][n] + memMinSum(grid, dp, m - 1, n);
        long long left = grid[m][n] + memMinSum(grid, dp, m, n - 1);

        return min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memMinSum(grid,dp,m-1,n-1);
        return spaMinSum(grid, m, n);
    }
};
