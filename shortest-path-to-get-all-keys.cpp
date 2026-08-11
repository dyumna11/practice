class Solution {
public:

    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size(),m=grid[0].size();
        int sr=0,sc=0,startmask=0;
       int keys=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]=='@')
                {
                    sr=i,sc=j;
                  
                }
                else if(grid[i][j]>='a' && grid[i][j]<='z')
                ++keys;
            }
        }
         vector<vector<vector<int>>> vis(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << keys, 0)
            )
        );
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int targetid=(1<<keys)-1;
       queue<tuple<int,int,int>>q;
       int steps=0;
       q.push({sr,sc,0});
       while(!q.empty())
       {
        int s=q.size();
        while(s--)
        {
        auto [r,c,mask]=q.front();q.pop();
        if(mask==targetid)
        return steps;
        for(int k=0;k<4;++k)
        {
            int nr=r+dr[k];
            int nc=c+dc[k];
         
    if(nr<0 || nc<0 || nr>=n || nc>=m)
    continue;
      char ch=grid[nr][nc];

    if(ch=='#')
   continue;
    int newmsk=mask;
    if(ch>='a' && ch<='z')
    {
        int key=ch-'a';
        newmsk|=1<<key;
    }
    else if(ch>='A' && ch<='Z')
    {
        int key=ch-'A';
       if (!(mask & (1 << key)))
        continue;
    }
     if(!vis[nr][nc][newmsk])
     {
        vis[nr][nc][newmsk]=1;
        q.push({nr,nc,newmsk});
     }
        }

    }
    ++steps;
       }
       return -1;
    }
};
