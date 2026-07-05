
    vector<int> findOrder(int n, vector<vector<int>> &pre) {
        // code here
        vector<vector<int>>adj(n);
        vector<int>ans;
        vector<int>inorder(n,0);
        queue<int>q;
        int c=0;
      for(auto p:pre)
      {
          int x=p[0];
         int y=p[1];
         adj[y].push_back(x);
         inorder[x]++;
      }
      for(int i=0;i<n;++i)
      {
          if(inorder[i]==0)
          q.push(i);
      }
      while(!q.empty())
      {
          int node=q.front();
          ans.push_back(node);
          q.pop();
          for(auto adjnode:adj[node])
          {
              inorder[adjnode]--;
              if(inorder[adjnode]==0)
              q.push(adjnode);
          }
      }
      if (ans.size() != n)
    return {};

return ans;
    }
