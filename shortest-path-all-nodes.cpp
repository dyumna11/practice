class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i)
        q.push({i,1<<i});
        int steps=0;
        vector<vector<int>>vis(n,vector<int>((1<<n),0));
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
            auto [node, msk]=q.front();
            q.pop();
            if(msk==(1<<n)-1)
            return steps;
            for(int adjnode:graph[node])
            {
                int newmsk=msk|1<<adjnode;
                if(!vis[adjnode][newmsk])
                {
                    vis[adjnode][newmsk]=1;
                    q.push({adjnode,newmsk});
                }
            }
            }
            steps++;

        }
        

    
return -1;
        
    }
};
