class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        if (n == 1) {
            return matrix[0][0];
        }
        int n_min = INT_MAX;
        vector<int> prev(n, 0);
        for (int lastRow = 0; lastRow < matrix.size(); lastRow++) {
            prev[lastRow] = matrix[n - 1][lastRow];
        }
        

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int min_path = INT_MAX;
                int temp1 = INT_MAX, temp2 = INT_MAX, temp3 = INT_MAX;
                if (j - 1 >= 0)
                    temp1 = matrix[i][j] + prev[j - 1];
                temp2 = matrix[i][j] + prev[j];
                if (j + 1 <= matrix.size() - 1)
                    temp3 = matrix[i][j] + prev[j + 1];
                min_path = min(min(temp1, temp2), temp3);
                curr[j] = min_path;
            }
            prev = curr;
        }
        int min_best=INT_MAX;
        for(int j=0;j<matrix.size();j++){
            min_best = min(min_best,prev[j]);
        }

        return min_best;
    }
};
