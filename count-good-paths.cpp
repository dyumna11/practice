class Solution {
public:
vector<int>parent;
vector<int>size;
int findparent(int x)
{
    if(parent[x]==x)
    return x;
    return parent[x]=findparent(parent[x]);
}
void unionbysize(int u,int v)
{
    int pu=findparent(u),pv=findparent(v);
    if(pu==pv)
    return;
    if(size[pu]>=size[pv])
    {
        size[pu]+=size[pv];
        parent[pv]=pu;
    }
    
    else
    {
    size[pv]+=size[pu];
     parent[pu]=pv;
    }
}
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
             int n=vals.size();
        vector<vector<int>>adj(n);
   
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;++i)
        parent[i]=i;
        int s=0;
        map<int,vector<int>>m;
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
         adj[e[1]].push_back(e[0]);
         
        }
        for(int i=0;i<n;++i)
        m[vals[i]].push_back(i);//acc to value add nodes in a vector
//initially all nodes are separate and inactive
       vector<bool>active(n,false);//to check whether it has been connected yet or not
       for(auto i:m)
       {
        vector<int> nodes=i.second;//find nodes with same value
        for(int node:nodes)
        {
             active[node] = true;//activate current node
            for(int adjnode:adj[node])
            {
                if(active[adjnode]&& vals[adjnode] <= vals[node])//if adjnode is active and satisfies condition
                unionbysize(adjnode,node);//union them
            }
            
            
        }
        unordered_map<int, int> countparents;//to count nodes with same parents
        
        for(int node:nodes)
        countparents[findparent(node)]++;//count those who have same parents
        for(auto i:countparents)
        {
            int c=i.second;//those who have same parents can be merged
            s+=c*(c+1)/2;
            //s+= c(all nodes are good)+ nC2 formula
            //use nC2 formula c*(c-1)/2, coz for a path to be made we need 2 nodes
        }

       }
       return s;
    }
};
