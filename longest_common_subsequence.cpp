class Solution {
public:
    //Space Optimization
    int spa(int ind1,int ind2,string text1,string text2){
        vector<int> prev(ind2+1,0);
        for(int j=0;j<ind2+1;j++){
            prev[j] = 0;
        }

        for(int i=1;i<ind1+1;i++){
            vector<int> curr(ind2+1,0);
            for(int j=1;j<ind2+1;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[ind2];
    }
    //Tabulation
    int tab(int ind1,int ind2,string text1,string text2){
        vector<vector<int>> dp(ind1+1,vector<int>(ind2+1,0));
        for(int i=0;i<ind1+1;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<ind2+1;j++){
            dp[0][j] = 0;
        }

        for(int i=1;i<ind1+1;i++){
            for(int j=1;j<ind2+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[ind1][ind2];
    }

    // Memoization (Time O(N*M))  Space O(N*M) + Auxiliary Stack space O(N+M)
    int longestUtil(int ind1,int ind2,string text1,string text2,vector<vector<int>> &dp){
        //index shifting concept
        if(ind1==0 || ind2==0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(text1[ind1-1]==text2[ind2-1]){
            return dp[ind1][ind2] = 1 + longestUtil(ind1-1,ind2-1,text1,text2,dp);
        }
        return dp[ind1][ind2] = max(longestUtil(ind1-1,ind2,text1,text2,dp),longestUtil(ind1,ind2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int ind1=text1.size();
        int ind2=text2.size();
        vector<vector<int>> dp(ind1+1,vector<int>(ind2+1,-1));
        // return longestUtil(ind1,ind2,text1,text2,dp);
        // return tab(ind1,ind2,text1,text2);
        return spa(ind1,ind2,text1,text2);
    }
};
