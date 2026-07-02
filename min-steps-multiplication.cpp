
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
