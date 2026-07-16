//for each node we find if it is equal to k or not
  int dfs(Node *root, int k,int s, unordered_map<int,int>&m)
  {
      if(!root)
      return 0;
      s+=root->data;
      int c=0;
      if(m.count(s-k))
       c=m[s-k];//use prefix sum technique
      m[s]++;
      c+=dfs(root->left,k,s,m);//move to left and right
       c+=dfs(root->right,k,s,m);
       m[s]--;//after finishing the node,it is necessary to backtrack
       return c;//returning for each node
  }
    int countAllPaths(Node *root, int k) {
        // code here
        int s=0;
        unordered_map<int,int>m;
        m[0]=1;//initialise for s==k
        return dfs(root,k,s,m);
    }
//tc=0(n), sc=o(h+n), h=height, n=if prefix sum stores all nodes
//Number of prefix sums stored simultaneously = only those on the current recursion path = O(h).
//therefore even after considering more paths sc remains o(h)
