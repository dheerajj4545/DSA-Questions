class Solution {
public:
    int dfs(int i,int j,vector<int>& piles,vector<vector<int>>&dp){
        if(i==j) return piles[i];
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int forward=piles[i]-dfs(i+1,j,piles,dp);
        int backward=piles[j]-dfs(i,j-1,piles,dp);
        return dp[i][j]=max(forward,backward);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        return dfs(0,n-1,piles,dp);
        
    }
};