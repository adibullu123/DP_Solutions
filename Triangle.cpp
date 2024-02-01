class Solution {

// basically followed a subsequence,by choosing every combination
public:
    // Memoized Solution
    int memMinTotal(int n, int picked, vector<vector<int>>& triangle,
                    vector<vector<int>>& dp) {
        if (n < 0) {
            return 0;
        }
        if (dp[n][picked] != -1) {
            return dp[n][picked];
        }
        int min_cost = INT_MAX;
        if (picked > triangle.size() - 1) {
            for (int z = 0; z <= n; z++) {
                int temp = triangle[n][z] + memMinTotal(n - 1, z, triangle, dp);
                min_cost = min(min_cost, temp);
            }
        } 
        else {
            int curr_i = INT_MAX;
            if (picked <= n) {
                curr_i = triangle[n][picked] +
                         memMinTotal(n - 1, picked, triangle, dp);
            }
            int curr_j = INT_MAX;
            if (picked - 1 >= 0) {
                curr_j = triangle[n][picked - 1] +
                         memMinTotal(n - 1, picked - 1, triangle, dp);
            }
            min_cost = min(curr_i, curr_j);
        }
        return dp[n][picked] = min_cost;
    }

    // Recursive Solution
    // int recMinTotal(int n, int picked, vector<vector<int>>& triangle) {
    //     if (n < 0) {
    //         return 0;
    //     }
    //     int min_cost = INT_MAX;

    //     // if it's the last row(starting point in top-down approach) we can try
    //     // any number in the n-1th vector
    //     if (picked > triangle.size()-1) {
    //         for (int i = 0; i <= n; i++) {
    //             int temp = triangle[n][i] + recMinTotal(n - 1, i, triangle);
    //             min_cost = min(min_cost, temp);
    //         }
    //     }
    //     // Once an index is selected,Constraint starts
    //     else {
    //         int curr_i = INT_MAX;
    //         if (picked <= n) {
    //             curr_i =
    //                 triangle[n][picked] + recMinTotal(n - 1, picked, triangle);
    //         }
    //         int curr_j = INT_MAX;
    //         if (picked - 1 >= 0) {
    //             curr_j = triangle[n][picked - 1] +
    //                      recMinTotal(n - 1, picked - 1, triangle);
    //         }
    //         min_cost = min(curr_i, curr_j);
    //     }
    //     return min_cost;
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int picked = triangle.size();
        int n = triangle.size();
        //dont forget to add extra space for dp vector (+1)
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return memMinTotal(n - 1, picked, triangle, dp);
        return tabMin(n,triangle);
    }
