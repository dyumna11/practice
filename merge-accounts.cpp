
vector<int>parent,size;
int findparent(int x)
{
    if(x==parent[x])
    return x;
    return parent[x]=findparent(parent[x]);
}
void unionsize(int u,int v)
{
    int pu=findparent(u),pv=findparent(v);
    if(pu==pv)
    return;
    if(size[pu]<size[pv])
    {
    parent[pu]=pv;
    size[pv]+=size[pu];
}
    else
    {
        parent[pv]=pu;
    size[pu]+=size[pv];
    }

}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>m;
 int n = accounts.size();   
  vector<vector<string>> ans;    
  parent.resize(n),size.resize(n,1);
        for(int i=0;i<n;++i)
        parent[i]=i;
        for(int i=0;i<accounts.size();++i)
        {
            for(int j=1;j<accounts[i].size();++j)
            {
                string email=accounts[i][j];
                if(m.find(email)==m.end())
                m[email]=i;
                else
                unionsize(i,m[email]);
            }
        }
         vector<string> merge[n];
        for(auto i:m)
        {
            string mail=i.first;
            int node=i.second;
            int ultpar=findparent(node);
            merge[ultpar].push_back(mail);
        }
        for(int i=0;i<accounts.size();++i)
        {
            if(merge[i].size()==0)
            continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto j:merge[i])
            {
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};
