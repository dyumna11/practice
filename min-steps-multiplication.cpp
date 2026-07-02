//since it is unweighted,bfs guarantees reaching by min number of multiplications, we can only use vis array and skip steps array completely
 //app1
int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        q.push({start,0});
        vector<int>steps(1001,INT_MAX);
        steps[start]=0;
        while(!q.empty())
        {
            int node=q.front().first;
            int step=q.front().second;
            if(node==end)
            return step;
            q.pop();
            for(int x:arr)
            {
                int newnode=(node*x)%1000;
                if(steps[newnode]>step+1)
                {
                    steps[newnode]=step+1;
                    if(newnode==end)
                    return steps[newnode];
                    q.push({newnode,step+1});
                }
                
            }
        }
        return -1;
    }
//app2

    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        q.push({start,0});
        vector<int>vis(1001,false);
        vis[start]=1;
        while(!q.empty())
        {
            int node=q.front().first;
            int step=q.front().second;
            if(node==end)
            return step;
            q.pop();
            for(int x:arr)
            {
                int newnode=(node*x)%1000;
                if(!vis[newnode])
                {
                    if(newnode==end)
                    return step+1;
                    q.push({newnode,step+1});
                    vis[newnode]=true;
                }
                
            }
        }
        return -1;
    }
