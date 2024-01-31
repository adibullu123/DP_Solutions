class Solution {
public:
    // Space Optimization
    int spaPath(int m, int n) {
        vector<int> prev(n,0);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n,0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {

                    temp[j] = 1;
                    continue;
                }
                int up = 0;
                if (i - 1 >= 0)
                    up = prev[j];

                int left = 0;
                if (j - 1 >= 0)
                    left = temp[j-1];

                temp[j] = up + left;
            }
            prev = temp;
        }
        return prev[n-1];
    }

    // Tabulation
    int tabPath(int m, int n) {
        // initialize dp vector and decide base case to build the solution from
        // the bottom
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    // base case included inside ,cos makes sense to do it
                    //.can do outside as well
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0;
                if (i - 1 >= 0)
                    up = dp[i - 1][j];

                int left = 0;
                if (j - 1 >= 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }

    // dp memoization
    int recPath(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 && n == 0) {
            return 1;
        }
        if (m < 0 || n < 0) {
            return 0;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        int up = recPath(m - 1, n, dp);
        int left = recPath(m, n - 1, dp);

        return dp[m][n] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return recPath(m - 1, n - 1, dp);
        return tabPath(m, n);
    }
};
