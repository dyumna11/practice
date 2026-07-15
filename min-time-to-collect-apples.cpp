class Solution {
public:
int dfs(int node,int parent, vector<vector<int>>&adj,vector<bool>& hasApple)
{
    int time=0;
    for(int child:adj[node])
    {
        if(child==parent)//usually in tree we dont want to iterate back
        continue;
        int timefromchild=dfs(child,node,adj,hasApple);//perform dfs on child
        if(timefromchild>0 || hasApple[child])
        time+=timefromchild+2;//add 2 for going and coming back from root
    }
    return time;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        queue<pair<int,int>>q;
        vector<vector<int>>adj(n);
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
       return dfs(0,-1,adj,hasApple);
    }
};
//tc O(v+e), in trees e=v-1 so tc= O(v)
//sc O(v)
