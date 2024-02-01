class Solution {
public:

    //Space Optimization 
    int spaTotal(vector<vector<int>>& triangle, int n) {
        // base cases
        vector<int> prev(n,0);
        for (int i = 0; i < n; i++) {
            prev[i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            vector<int> temp(i+1,0);
            for (int j = i; j >=0 ; j--) {
             int next = triangle[i][j] + prev[j];
             int next2 = triangle[i][j] + prev[j+1];

                temp[j] = min(next, next2);
            }
            prev=temp;
        }
        return prev[0];
    }
    // Tabulation
    int tabTotal(vector<vector<int>>& triangle, int n) {
        vector<vector<int>> dp(n, vector<int>(n , 0));
        // base cases
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >=0 ; j--) {
             int next = triangle[i][j] + dp[i+1][j];
             int next2 = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(next, next2);
            }
        }
        return dp[0][0];
    }
    // Memoization
    int recTotal(vector<vector<int>>& triangle, int n, int picked,
                 vector<vector<int>>& dp) {
        if (n == triangle.size() - 1) {
            return triangle[n][picked];
        }
        if (dp[n][picked] != -1) {
            return dp[n][picked];
        }
        int next = triangle[n][picked] + recTotal(triangle, n + 1, picked, dp);
        int next2 =
            triangle[n][picked] + recTotal(triangle, n + 1, picked + 1, dp);

        return dp[n][picked] = min(next, next2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n , -1));
        // return recTotal(triangle, 0, 0, dp);
        // return tabTotal(triangle,n);
        return spaTotal(triangle,n);
    }
};
