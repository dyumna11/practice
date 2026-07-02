
  vector<int>in;
  void inorder(Node* root)
  {
      if(!root)
      return;
      inorder(root->left);
      in.push_back(root->data);
      inorder(root->right);
  }
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int>ans;
       deque<int>pq;
       inorder(root);
      for(int i=0;i<in.size();++i)
      {
          if(pq.size()<k)
          pq.push_back(in[i]);
          else
          {
         if(abs(in[i]-target)<abs(pq.front()-target))
          {
              pq.pop_front();
              pq.push_back(in[i]);
          }
          else
          break;
      }
      }
    
    return vector<int>(pq.begin(), pq.end());

    }
