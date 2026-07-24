class Solution {
public:
void dfs(vector<int>&dist,int node,vector<int>& edges,vector<int>&vis)
{
    //vis needed because it contains cycles
    if (node == -1 || vis[node])
        return;//if v==-1 we cannot go further
    vis[node] = true;
    int v=edges[node];
    if(v!=-1&& !vis[v])
    {
    dist[v]=dist[node]+1;
    dfs(dist,v,edges,vis);
    }
}
void bfs(vector<int>&dist,int node,vector<int>& edges,vector<int>&vis)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;
    while(!q.empty())
    {
        int adjnode=q.front();
        q.pop();
        int nxt=edges[adjnode];
        if( nxt!=-1 && !vis[nxt] )
        {
        dist[nxt]=dist[adjnode]+1;
        vis[nxt]=1;
        q.push(nxt);
        }
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
      
      int n=edges.size();
       vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);
        dist1[node1]=0,dist2[node2]=0;
        vector<int>vis1(n,false);
        vector<int>vis2(n,false);
        bfs(dist1,node1,edges,vis1);//run dfs or bfs from nodes
        bfs(dist2,node2,edges,vis2);//find min distance to all nodes
        int ans=-1;
        int mx=0,mn=INT_MAX;
        
        for(int i=0;i<n;++i)
        {
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX)//if unreachable continue
        continue;
            mx=max(dist1[i],dist2[i]);//find max dist
           if(mx<mn)
           {
            mn=mx;//then go for min and store ans
            ans=i;
           }
        }
        return ans;
    }
};
