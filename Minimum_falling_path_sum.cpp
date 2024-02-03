class Solution {
public:
    //Space Optimization
    int spaMinPath(int n,vector<vector<int>> &matrix){
        //base case
        int n_min = INT_MAX;
        vector<int> prev(n+1,0);
        for(int lastRow = 0;lastRow<matrix.size();lastRow++){
            prev[lastRow] = matrix[n-1][lastRow];
            n_min = min(n_min,prev[lastRow]);
        }
        prev[n] = n_min;

        for(int i=n-2;i>=0;i--){
            vector<int> curr(n+1,0);
            for(int j = 0;j<=n;j++){
                int min_path = INT_MAX;
                if(j == matrix.size()){
                    for(int start = 0;start<matrix.size();start++){
                        int temp = curr[start];
                        min_path = min(min_path,temp);
                    }
                }
                else{
                    int temp1 =INT_MAX,temp2 =INT_MAX,temp3 =INT_MAX;
                    if(j-1>=0)
                    temp1 = matrix[i][j] + prev[j-1]; 
                    temp2 = matrix[i][j] + prev[j];
                    if(j+1<=matrix.size()-1)
                    temp3 = matrix[i][j] + prev[j+1];
                    min_path = min(min(temp1,temp2),temp3);
                }
                curr[j] = min_path;
            }
            prev = curr;
        } 
        return prev[n];
    }
    //Tabulation
    int tabMinPath(int n,vector<vector<int>> &matrix){
        //dp vector
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        //base case
        int n_min = INT_MAX;
        for(int lastRow = 0;lastRow<matrix.size();lastRow++){
            dp[n-1][lastRow] = matrix[n-1][lastRow];
            n_min = min(n_min,dp[n-1][lastRow]);
        }
        dp[n-1][n] = n_min;

        for(int i=n-2;i>=0;i--){
            for(int j = 0;j<=n;j++){
                int min_path = INT_MAX;
                if(j == matrix.size()){
                    for(int start = 0;start<matrix.size();start++){
                        int temp = dp[i][start];
                        min_path = min(min_path,temp);
                    }
                }
                else{
                    int temp1 =INT_MAX,temp2 =INT_MAX,temp3 =INT_MAX;
                    if(j-1>=0)
                    temp1 = matrix[i][j] + dp[i+1][j-1]; 
                    temp2 = matrix[i][j] + dp[i+1][j];
                    if(j+1<=matrix.size()-1)
                    temp3 = matrix[i][j] + dp[i+1][j+1];
                    min_path = min(min(temp1,temp2),temp3);
                }
                dp[i][j] = min_path;
            }
        } 
        return dp[0][n];
    }
    //Memoization
    int recMinPath(int n,vector<vector<int>> &matrix,int picked,vector<vector<int>>&dp){
        if(n==matrix.size()-1){
            return matrix[n][picked];
        }
        if(dp[n][picked]!=-1){
            return dp[n][picked];
        }
        int min_path = INT_MAX;
        if(picked == matrix.size()){
            for(int start = 0;start<matrix.size();start++){
                int temp = recMinPath(n,matrix,start,dp);
                min_path = min(min_path,temp);
            }
        }
        else{
            int temp1 =INT_MAX,temp2 =INT_MAX,temp3 =INT_MAX;
            if(picked-1>=0)
            temp1 = matrix[n][picked] + recMinPath(n+1,matrix,picked-1,dp); 
            temp2 = matrix[n][picked] + recMinPath(n+1,matrix,picked,dp);
            if(picked+1<=matrix.size()-1)
            temp3 = matrix[n][picked] + recMinPath(n+1,matrix,picked+1,dp);
            min_path = min(min(temp1,temp2),temp3);
        }
        return dp[n][picked] = min_path;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int picked = matrix.size();
        int n = matrix.size();
        if(picked==1){
            return matrix[0][0];
        }
        //dp
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return recMinPath(0,matrix,picked,dp);
        // return tabMinPath(n,matrix);
        return spaMinPath(n,matrix);

    }
};
