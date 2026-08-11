class Solution {
public:
int dfs(int i,int j,vector<vector<int>>& grid, int rem,vector<vector<int>>& vis)
{
    int n=grid.size(),m=grid[0].size();
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    int ans=0;
    if(grid[i][j]==2)
    {
        return rem == 0 ? 1 : 0;
    }
    if(vis[i][j] || grid[i][j]==-1)
    return 0;
   vis[i][j]=1;
    for(int k=0;k<4;++k)
    {
        int nr=i+dr[k];
        int nc=j+dc[k];
        if(nr<0 || nr>=n || nc<0 || nc>=m)
        continue;
        if(vis[nr][nc] || grid[nr][nc]==-1)
        continue;
            ans+=dfs(nr,nc,grid,rem-1,vis);
        }
    
   vis[i][j]=0;
    return ans;
}
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int total=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int sr=0,sc=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1)
                {
                     sr=i,sc=j;
                }
                 if (grid[i][j]!=-1)
                ++total;
            }
        }
       return dfs(sr,sc,grid,total-1,vis);
        
    }
};
