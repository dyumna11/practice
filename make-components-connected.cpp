
    vector<int> parent, size;

    int findparent(int x)
    {
        if(x == parent[x])
            return x;

        return parent[x]
             = findparent(parent[x]);
    }

    void findunion(int u, int v)
    {
        int pu = findparent(u);
        int pv = findparent(v);
        if(pu == pv)
            return;
        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int makeConnected(
        int n,
        vector<vector<int>>& connect)
    {
        if(connect.size() < n - 1)
            return -1;
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
        int extra = 0;

        for(int i = 0; i < connect.size(); ++i)
        {
            int u = connect[i][0];
            int v = connect[i][1];
                findunion(u,v);
        }
        int c = 0;
        for(int i = 0; i < n; ++i)
        {
            if(findparent(i) == i)
                c++;
        }
    return c - 1;

        return -1;
    }
