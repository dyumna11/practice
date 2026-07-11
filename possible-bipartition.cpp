//same as if we need to color the graph in 2 colors, st no adj has same color
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,-1);
        queue<int>q;
       
        vector<vector<int>>adj(n+1);//always initialise list with size
        for(auto &i:dislikes)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=n;++i)//start from all nodes as we dont know thr starting point
        {
            if(color[i]!=-1)
            continue;
            color[i]=0;
            q.push(i);
        while(!q.empty())
        {
            int person=q.front();
            q.pop();
            for(auto i:adj[person])
            {
                if(color[i]==-1)
                {
                    color[i]=!color[person];
                    q.push(i);
                }
                else
                {
                    if(color[i]==color[person])
                    return false;
                }
            }
        }
        }
        return true;
    }
