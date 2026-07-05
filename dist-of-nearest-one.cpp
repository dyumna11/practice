
    vector<vector<int>> nearest(vector<vector<int>>& a) {
        // code here
        int n=a.size(),m=a[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
         vector<vector<int>> ans(n,vector<int>(m,0));
          vector<vector<int>> vis(n,vector<int>(m,0));
         queue<pair<int,int>>q;
         for(int i=0;i<n;++i)
         {
             for(int j=0;j<m;++j)
             {
                 if(a[i][j]==1)
                 {
                 q.push({i,j});
                 vis[i][j]=1;
             }
             }
         }
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;++k)
            {
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && a[nr][nc]==0 && !vis[nr][nc])
                {
                    ans[nr][nc]=ans[r][c]+1;
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        return ans;
    }
