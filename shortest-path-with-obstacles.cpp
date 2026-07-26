class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<tuple<int,int,int,int>>q;
        int n=grid.size(),m=grid[0].size();
        q.push({0, 0,0,0});
         int dr[]={-1,0,1,0};
          int dc[]={0,1,0,-1};
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>best(n,vector<int>(m,INT_MAX));
        best[0][0]=0;
          vis[0][0]=1;
        while(!q.empty())
        {
            auto [steps,obs,r,c]=q.front();q.pop();
            if(obs>k)
            continue;
            if(r==n-1 && c==m-1)
            return steps;
            
            for(int i=0;i<4;++i)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nc<0 || nr>=n || nc>=m)
                continue;
                 int newObs = obs + grid[nr][nc];
                  if (newObs <= k && newObs < best[nr][nc]) 
                  {
        best[nr][nc] = newObs;
        q.push({steps + 1, newObs, nr, nc});
            }
        }
        }
        return -1;
    }
};
