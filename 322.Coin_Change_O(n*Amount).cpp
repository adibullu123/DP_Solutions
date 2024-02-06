class Solution {
public:

    // //Tabulation
    long long tabCoinChange(int n, int amount, vector<int>& coins) {
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, INT_MAX));

        // Base case initialization
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < amount + 1; j++) {
                long long pick = (j >= coins[i]) ? 1 + dp[i][j - coins[i]] : INT_MAX;
                long long not_pick = (i > 0) ? dp[i - 1][j] : INT_MAX;
                dp[i][j] = min(pick, not_pick);
            }
        }

        return dp[n - 1][amount] ;
    }

    // Memoization Solution
    long long recurCoinChange(int n, int amount, vector<int>& coins,
                              vector<vector<long long>>& dp) {
        if (amount == 0) {
            return 0;
        }
        if (n < 0) {
            return INT_MAX;
        }
        if (dp[n][amount] != -1) {
            return dp[n][amount];
        }
        long long pick = INT_MAX;
        if (amount >= coins[n])
            pick = 1 + recurCoinChange(n, amount - coins[n], coins, dp);
        long long not_pick = recurCoinChange(n - 1, amount, coins, dp);

        return dp[n][amount] = min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, -1));
        // long long curr =  recurCoinChange(n-1,amount,coins,dp);
        long long curr = tabCoinChange(n , amount, coins);

        if (curr == INT_MAX) {
            return -1;
        }
        return curr;
    }
};
