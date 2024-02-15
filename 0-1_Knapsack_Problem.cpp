//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Space Optimized code
    int spa(int n,int W,vector<int> &wgt,vector<int> &score){
        //create dp vector
        vector<int> prev(W+1,0);
        
        //initialize base case to build bottom-up solution
        for(int weight=0;weight<=W;weight++){
            if(weight >=wgt[0]) prev[weight] = score[0];
        }
        // weight = 0 base case
        
        for(int i=0;i<n;i++){
            prev[0] = 0;
        }
        
        for(int i=1;i<n;i++){
            vector<int> temp(W+1,0);
            for(int j=1;j<=W;j++){
                
                int pick =(j>=wgt[i])? score[i]+ prev[j-wgt[i]]:INT_MIN;
                int not_pick = prev[j];
                
                temp[j] = max(pick,not_pick);
            }
            prev = temp;
        }
        
        return prev[W];
    }
    // Tabulation Code
    int tab(int n,int W,vector<int> &wgt,vector<int> &score){
        //create dp vector
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        
        //initialize base case to build bottom-up solution
        for(int weight=0;weight<=W;weight++){
            if(weight >=wgt[0]) dp[0][weight] = score[0];
        }
        // weight = 0 base case
        
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=W;j++){
                
                int pick =(j>=wgt[i])? score[i]+ dp[i-1][j-wgt[i]]:INT_MIN;
                int not_pick = dp[i-1][j];
                
                dp[i][j] = max(pick,not_pick);
            }
        }
        
        return dp[n-1][W];
    }
    //Memoized Solution
    int mem(int n,int W,vector<int> &wgt,vector<int> &score,vector<vector<int>> &dp){
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        if(W==0){
            return 0;
        }
        if(n==0){
            if(W >= wgt[n]){
                return score[n];
            }
            else return 0;
        }
        int pick =(W>=wgt[n])? score[n]+ mem(n-1,W-wgt[n],wgt,score,dp):INT_MIN;
        int not_pick = mem(n-1,W,wgt,score,dp);
        
        return dp[n][W] = max(pick,not_pick);
    }
    // Brute Force
    int recur(int n,int W,vector<int> &wgt,vector<int> &score){
        // code here
        if(W==0){
            return 0;
        }
        if(n==0){
            if(W >= wgt[n]){
                return score[n];
            }
            else return 0;
        }
        int pick =(W>=wgt[n])? score[n]+recur(n-1,W-wgt[n],wgt,score):INT_MIN;
        int not_pick = recur(n-1,W,wgt,score);
        
        return max(pick,not_pick);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       //convert array into vector
       vector<int> wgt(wt,wt+n);
       vector<int> score(val,val+n);
       
       //dp vector for memoization
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       
    //   return mem(n-1,W,wgt,score,dp);
    //   return tab(n,W,wgt,score);
      return spa(n,W,wgt,score);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
