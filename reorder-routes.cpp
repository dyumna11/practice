class Solution {
public:
int dfs(int node,int parent, vector<vector<pair<int,int>>>&adj)
{
    int cost=0;
    for(auto x:adj[node])
    {
        int child=x.first;
        int price=x.second;
        if(child==parent)//it should not go back
        continue;
        cost+=price;//as we are iterating through our adj, we keep adding whatever we have stored
        cost+=dfs(child,node,adj);
    }
return cost;

}
    int minReorder(int n, vector<vector<int>>& connections) {
      //we start from 0, so all edges must point towards it, if it is 0->u->v, then cost is required
      //in that case in adj list we add 1, otherwise add 0
      //while traversing we just add to the cost, so if reversal is required it is added
        vector<vector<pair<int,int>>>adj(n);
        for(auto c:connections)
        {
            adj[c[0]].push_back({c[1],1});//from 0->1, reversal required
            adj[c[1]].push_back({c[0],0});
        }
        return dfs(0,-1,adj);
    }
};
