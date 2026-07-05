class Solution {
public:
vector<int>par,size;
int parent(int x)
{
    if(x==par[x])
    return x;
    return par[x]=parent(par[x]);
}
void unionsize(int u,int v)
{
    int pu=parent(u),pv=parent(v);
    if(pu==pv) return;
    if(size[pu]>size[pv])
    {
       par[pv]=pu;
       size[pu]+=size[pv];
    }
    else
    {
        par[pu]=pv;
       size[pv]+=size[pu];
    }

}
    int largestIsland(vector<vector<int>>& grid) {
        int mx=0,ans=0,n=grid.size(),m=grid[0].size();
       par.resize(n*n);
       size.resize(n*n,1);
       for(int i=0;i<n*n;++i)
       par[i]=i;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]!=1)
                continue;
                for(int k=0;k<4;++k)
                {
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    int node=n*i+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
                    {
                        int adjnode=n*nr+nc;
                        unionsize(node,adjnode);
                    }
                
              
                }
                  
            }
        }
      
     for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==0)
                {
                    int curr=0;
                    set<int>s;
                    for(int k=0;k<4;++k)
                {
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
                    {
                       s.insert(parent(n*nr+nc)); 
                    }
                }
                for(auto i:s)
                {
                    curr+=size[i];
                }
                mx=max(mx,curr+1);
                }
            }
        }
 for(int i=0;i<n*n;i++)
{
    if(parent(i)==i)
        mx=max(mx,size[i]);
}
        return mx;
    }
};
