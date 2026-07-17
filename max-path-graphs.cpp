
  int memo(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& a)
  {
      int n=a.size(),m=a[0].size();
      if(i<0 || i>=n || j<0 || j>=m)
      return -1e9;
      if(i==n-1)
      return a[i][j];
      if(dp[i][j]!=-1)
      return dp[i][j];
      int left=a[i][j]+memo(i+1,j-1,dp,a);
      int right=a[i][j]+memo(i+1,j,dp,a);
      int down=a[i][j]+memo(i+1,j+1,dp,a);
      return dp[i][j]=max({left,right,down});
     
  }
    int maximumPath(vector<vector<int>>& a) {
        // code here
        int n=a.size(),m=a[0].size(),mx=-1;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j=0;j<m;++j)
        mx=max(mx,memo(0,j,dp,a));
        return mx;
    }
};
