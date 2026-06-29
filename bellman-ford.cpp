//used when graph weights are -ve
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        //we move till n-1 iterations coz the max distance from src to any node is n-1
         vector<int>dst(V,1e8);
         dst[src]=0;
        for(int i=0;i<V-1;++i)
        {
            for(auto e:edges)
            {
                int u=e[0],v=e[1],wt=e[2];
                if(dst[u]!=1e8 && dst[u]+wt<dst[v])
                {
                    dst[v]=dst[u]+wt;
                }
            }
        } //used to detect cycle, if even after n iterations, dst is dec then it means we are stuck in a loop
        for(auto e:edges)
            {
                int u=e[0],v=e[1],wt=e[2];
                if(dst[u]!=1e8 && dst[u]+wt<dst[v])
                {
                   return {-1};
                }
            }
            return dst;
    }

