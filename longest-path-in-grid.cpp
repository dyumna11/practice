class Solution {
  public:
  int memo(int i,int j,int xd,int yd, vector<vector<bool>>&vis,vector<vector<int>>& grid)
  {
      int n=grid.size(),m=grid[0].size();
    
      int ans=-1;
      if (i == xd && j == yd)
            return 0;
              vis[i][j]=1;
            int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
      for(int k=0;k<4;++k)
      {
          int nr=i+dr[k];
          int nc=j+dc[k];
          if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc])//explore all paths
          {
              int temp=memo(nr,nc,xd,yd,vis,grid);
              if(temp != -1)
              ans = max(ans, 1 + temp);//take max of all
          }
      }
      vis[i][j]=false;//backtracking
      return ans;
  }
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        if(mat[xs][ys] == 0 || mat[xd][yd] == 0)
    return -1;
        return memo(xs,ys,xd,yd,vis,mat);
    }
};
