//using dsu, tc= const 0(n*alpha)
    vector<int> parent, size;
    int findparent(int x)
    {
        if(parent[x] == x)
            return x;
        return parent[x] =
            findparent(parent[x]);
    }

    void unionsize(int x, int y)
    {
        int px = findparent(x);
        int py = findparent(y);

        if(px == py)
            return;

        if(size[px] > size[py])
        {
            parent[py] = px;

            size[px] += size[py];
        }
        else
        {
            parent[px] = py;

            size[py] += size[px];
        }
    }

    int removeStones(vector<vector<int>>& stones)
    {
        int mxrow = 0;
        int mxcol = 0;

        for(auto &it : stones)
        {
            mxrow = max(mxrow, it[0]);
            mxcol = max(mxcol, it[1]);
        }

        int total = mxrow + mxcol + 2;

        parent.resize(total);
        size.resize(total,1);

        for(int i = 0; i < total; ++i)
            parent[i] = i;

        map<int,int> nodes;

        for(auto &it : stones)
        {
            int r = it[0];
            int c = it[1] + mxrow + 1;
            unionsize(r,c);
            nodes[r] = 1;
            nodes[c] = 1;
        }

        int components = 0;

        for(auto &it : nodes)
        {
            if(findparent(it.first) == it.first)
                components++;
        }

        return stones.size() - components;
    }
//---------------------------------------------------------

//using dfs

  void dfs(int index,vector<int>&vis,vector<vector<int>>& stones)
  {
    int n=stones.size();
    vis[index]=true;
    for(int i=0;i<n;++i)
    {
        int r=stones[index][0];
        int c=stones[index][1];
        if(!vis[i] && (stones[i][0]==r || stones[i][1]==c))
        {
            dfs(i,vis,stones);
        }
    }

  }

    int removeStones(vector<vector<int>>& stones)
    {
          int n=stones.size();
        vector<int>vis(n,0);
        int group=0;
          
       for(int i=0;i<n;++i)
       {
        if(vis[i]==true)
        continue;
        dfs(i,vis,stones);
        ++group;
       }
       return n-group;
    }
//tc o(n*n) sc o(n) 
