//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution{
  public:
    // Space Optimization
    int spa(int n,vector<int> &cost){
        vector<int> prev(n+1,0);
        
        //base cases n==1
        for(int j = 1;j<n+1;j++){
            prev[j] = (j >= 1) ? cost[0]*j : 0;
        }
        
        for(int i = 2;i<n+1;i++){
            vector<int> temp(n+1,0);
            for(int j=1;j<n+1;j++){
                
                int pick = (j>=i)? cost[i-1] + temp[j-i]:INT_MIN;
                int not_pick = prev[j];
                
                temp[j] =  max(pick,not_pick);
            }
            prev = temp;
        }
        return prev[n];
    }
    //Tabulation
    int tab(int n,int curr_len,vector<int> &cost){
        //dp vector
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        //base cases n==1
        for(int j = 1;j<n+1;j++){
            dp[1][j] = (j >= 1) ? cost[0]*j : 0;
        }
        
        for(int i = 2;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                
                int pick = (j>=i)? cost[i-1] + dp[i][j-i]:INT_MIN;
                int not_pick = dp[i-1][j];
                
                dp[i][j] =  max(pick,not_pick);
            }
        }
        return dp[n][curr_len];
    }
    //Memoization
    int mem(int n,int curr_len,vector<int> &cost, vector<vector<int>> &dp){
        if(n==1){
            if(curr_len>=n){
                return cost[n-1] + mem(n,curr_len-n,cost,dp);
            }
            else return 0;
        }
        if(curr_len==0){
            return 0;
        }
        if(dp[n][curr_len]!=-1)return dp[n][curr_len];
    
        int pick = (curr_len>=n)? cost[n-1] + mem(n,curr_len-n,cost,dp):INT_MIN;
        int not_pick = mem(n-1,curr_len,cost,dp);
        
        return dp[n][curr_len] =  max(pick,not_pick);
    }

    int cutRod(int price[], int n) {
        //code here
        vector<int> cost(price,price+n);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return recur(n,n,cost);
        // return mem(n,n,cost,dp);
        // return tab(n,n,cost);
        return spa(n,cost);

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
