class Solution {
  public:
  int memo(int i,int j, vector<vector<int>>&dp)
  {
      if(i==0 && j==0)
      return 1;
      if(i<0 || j<0)
      return 0;
      if(dp[i][j]!=-1)
      return dp[i][j];
      int up=memo(i,j-1,dp);
      int left=memo(i-1,j,dp);
      return dp[i][j]=up+left;
  }
    int numberOfPaths(int m, int n) {
        // code here
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return memo(m-1,n-1,dp);
    }
};
