class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
       int n=routes.size();
       if(target==source)
       return 0;
       unordered_map<int, vector<int>> adj;
      //instead of storing buses, store stops for buses
      //so adj[stop]-- bus
        for(int i=0;i<n;++i)
        {
            for(int stop:routes[i])
            {
                adj[stop].push_back(i);
            }
        }
        queue<pair<int,int>>q;
        vector<int>vis(n,0);
        unordered_set<int>visstop;
        for(int bus : adj[source])//add all buses in the queue since we have to count them
{
    q.push({bus,1});
    vis[bus]=1;
}
        while(!q.empty())
        {
            int bus=q.front().first, count=q.front().second;
            q.pop();
           
            for(int stop:routes[bus])//so stops in this bus
            {
                if(stop==target)//check if target
                return count;
                if(visstop.count(stop))
                continue;
                visstop.insert(stop);
                for(int nxtbus:adj[stop])//next bus from this stop
                {
                    if(!vis[nxtbus])
                    {
                    vis[nxtbus]=1;
                    q.push({nxtbus,count+1});
                    }
                }
            }
        }
        return -1;
    }
};
