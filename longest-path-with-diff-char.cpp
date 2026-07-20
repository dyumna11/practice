//follows similar apporach to binary tree max sum
//except here it is a tree- many children
//there we had only 2 children so we took them for considering the path
//here the number of children were more so we take the second longest and longest
int ans=1;
int dfs(int node,string&s,vector<vector<int>>&adj)
{

   int mxpath=0,secondpath=0;
    for(int adjnode:adj[node])
    {
         
        int path=dfs(adjnode,s,adj);//find path first
        if(s[node]==s[adjnode])//if this condition is true, do not continue in this path
          //do not use return, coz then entire subtree becomes invalid
         continue;
         path++;
        if(path>mxpath)
        {
            secondpath=mxpath;
           mxpath=path;
        }
        else if(secondpath<path)
        secondpath=path;
        ans=max(ans,1+secondpath+mxpath);//update max
    }
    return mxpath;//return the path
}
    int longestPath(vector<int>& parent, string s) {
         int n=parent.size();
        vector<vector<int>>adj(n);
       
        for(int i=1;i<n;++i)//start from 1 coz parent [0]=-1
        {
            adj[parent[i]].push_back(i);//this is a directed graph
        }
        dfs(0,s,adj);

        return ans;
    }
};
