
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0)
        return -1;
       queue<pair<pair<int,int>, int>> q;
        q.push({{0,0},1});
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
              if (r == n-1 && c == n-1)
                return d;
            for(int i=0;i<8;++i)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0)
                {
                    q.push({{nr,nc},d+1});
                    grid[nr][nc]=1;
                }
            }


        }
        return -1;
    }
